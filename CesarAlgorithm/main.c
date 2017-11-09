#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE_OF_INPUTED_STRING 1000000
#define SIZE_OF_ALPHABET 26

//func prototypes
void dencryptFunc(char* enteredString, int keyForCipher);
void encryptFunc(char* enteredString, int keyForCipher);
int validateFuncArgs(int argc, char** argv);
int gotCesarCode(void);
char* gotString(void);


int main(int argc, char** argv) {
    
    if (validateFuncArgs(argc, argv)){
        return 0;
    }
    int codeCesar = gotCesarCode();
    char* enteredString = gotString();
    
    if (!strcmp (argv[1], "-e")){
        encryptFunc(enteredString, codeCesar);
    }
    
    if (!strcmp (argv[1], "-d")){
        dencryptFunc(enteredString, codeCesar);
    }
    printf("Result: ");
    puts(enteredString);
    free(enteredString);
    return 0;
}

//validate arguments
int validateFuncArgs(int argc, char** argv ){
    
    //check if user enters lower than one symbol (arguments)
    if (argc <= 1){
        printf("ATTENTION! For correct running use arguments: -e: for encryption; -d: for decription");
        return 1;
    }
    
    //check if user enters correct arguments
    if (!strcmp (argv[1], "-e") || !strcmp (argv[1], "-d")){
        return 0;
    }
    else {
        printf("ATTENTION! For correct running use arguments: -e: for encryption; -d: for decription");
        return 1;
    }
}

//eccrypt function
void encryptFunc(char* enteredString, int codeCesar){
    
    for(int i = 0; i < strlen(enteredString); i++){
        if (isalpha(enteredString[i])){
            if(isupper(enteredString[i])){
                enteredString[i] = ((enteredString[i] - 'A' + codeCesar) % 26) + 'A';
                
            }
            else{
                enteredString[i] = ((enteredString[i] - 'a' + codeCesar) % 26) + 'a';
            }
        }
    }
}

//decrypt function
void dencryptFunc(char* enteredString, int codeCesar){
    
    for(int i = 0; i < strlen(enteredString); i++){
        if (isalpha(enteredString[i])){
            if(isupper(enteredString[i])){
                enteredString[i] = ((enteredString[i] - 'A' - codeCesar + 26) % 26) + 'A';
            }
            else{
                enteredString[i] = ((enteredString[i] - 'a' - codeCesar + 26) % 26) + 'a';
            }
        }
    }
}

// get string function
char* gotString(){
    printf("Pls enter string which you want to use: ");
    char* inputerdString;
    inputerdString = (char*) malloc(SIZE_OF_INPUTED_STRING * sizeof(char));
    gets(inputerdString);
    
    if (inputerdString[0] == 0){
        printf("Error! Empty string\n");
    }
    fpurge(stdin);
    return inputerdString;
}

//get Cesar code function
int gotCesarCode(){
    int isDigitEntered = 0;
    int codeCesar;
    
    //enter until it will be digit
    do {
        printf("Pls enter Cesar code (digit): ");
        isDigitEntered = scanf("%d", &codeCesar);
    } while (!isDigitEntered);
    fpurge(stdin);
    
    //check if entered code more than size of alphabet
    if (codeCesar > SIZE_OF_ALPHABET){
        codeCesar = codeCesar % SIZE_OF_ALPHABET;
    }
    return codeCesar;
}

