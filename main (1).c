#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Name {// Ýsim verileri için bir struct tanýmladým
    char isim[50];
};

int karsilastir(const void *a, const void *b) {
    return strcmp(((struct Name*)a)->isim, ((struct Name*)b)->isim);
}

int binarySearch(struct Name names[], int n, char *aranan) {
    int bas = 0, son = n - 1;
    while (bas <= son) {
        int orta = bas + (son - bas) / 2;
        int cmp = strcmp(names[orta].isim, aranan);
        if (cmp == 0) {
            return orta; // Ýstenilen kelimeyi bulunca ortayý döndürür
        } else if (cmp < 0) {
            bas = orta + 1;
        } else {
            son = orta - 1;
        }
    }
    return -1; // Ýstenilen kelimeyi bulamayýnca -1 döndürür.
}

int main() {
    struct Name names[200];
    char aranan[50];
    int satir_sayisi = 0;
char dosya_ad[50];
printf("dosya adýný giriniz:");
scanf("%s",dosya_ad);
    
    FILE *file = fopen(dosya_ad, "r");// Dosyayý açýp verileri okuma
    if (file == NULL) {
        perror("Dosya açýlmadý");
        return 1;
    }

    while (fscanf(file, "%s", names[satir_sayisi].isim) == 1) {
    satir_sayisi++;
    }

    fclose(file);
    qsort(names, satir_sayisi, sizeof(struct Name), karsilastir);// Verileri sýralama

    printf("Aranacak ismi girin: ");
    scanf("%s", aranan);

    int sonuc = binarySearch(names, satir_sayisi, aranan);
    if (sonuc != -1) {
        printf("Ýstenilen kelime '%s' bulundu.\n", aranan);
    } else {
        printf("Ýstenilen kelime bulunamadý.\n");
    }

    return 0;
}

