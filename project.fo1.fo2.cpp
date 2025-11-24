#include <stdio.h>
#include <string.h>

typedef struct {
    char accountId[20];
    char fullName[50];
    char phone[15];
    double balance;
    int status; // 1 = active, 0 = locked
} Account;

typedef struct {
    char transId[20];
    char senderId[20];
    char receiverId[20];
    double amount;
    char type[10];
    char date[20];
} Transaction;

// Mang du lieu
Account accounts[100];
int accountCount = 0;

// Prototype (khai báo truoc da su dung)
int findAccountById(char id[]);
void addAccount();
void updateAccount();

int findAccountById(char id[]) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountId, id) == 0) {
            return i; // tìm thay ? tra ve vi trí trong mang
        }
    }
    return -1; // không tìm thay
}

void addAccount() {
    Account acc;

    printf("\n=== THEM TAI KHOAN MOI ===\n");

    printf("Nhap ID tai khoan: ");
    scanf("%s", acc.accountId);

    // Kiem tra ID trùng
    if (findAccountById(acc.accountId) != -1) {
        printf("? ID nay da ton tai! Khong the tao moi.\n");
        return;
    }

    printf("Nhap Ho ten: ");
    scanf(" %[^\n]", acc.fullName);

    printf("Nhap so dien thoai: ");
    scanf("%s", acc.phone);

    // Giá tri mac dinh khi tao tài khoan
    acc.balance = 0;
    acc.status = 1; // active

    // Luu vào mang
    accounts[accountCount++] = acc;

    printf("?? Tao tai khoan thanh cong!\n");
}

void updateAccount() {
    char id[20];
    printf("\n=== CAP NHAT THONG TIN TAI KHOAN ===\n");

    printf("Nhap ID tai khoan can cap nhat: ");
    scanf("%s", id);

    int index = findAccountById(id);

    if (index == -1) {
        printf("? Khong tim thay tai khoan!\n");
        return;
    }

    printf("Nhap ten moi: ");
    scanf(" %[^\n]", accounts[index].fullName);

    printf("Nhap so dien thoai moi: ");
    scanf("%s", accounts[index].phone);

    printf("?? Cap nhat thanh cong!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Them tai khoan\n");
        printf("2. Cap nhat tai khoan\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                updateAccount();
                break;
            case 0:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}

