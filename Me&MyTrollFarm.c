#include <stdio.h>
#include <stdlib.h>
void startMenu();
void quitSubmenu();
void tutorialSubmenu();
void playGame();
void calcScore(int choice, int *score);
void linebylineFile(char* file_to_open);
void wholeFile (char* file_to_open);
void userChoice();
void scriptChoice(int i, int size);
int choice, score = 0, i, size;

char *header_filelist[] = {
                            "./txts/000.txt",   //0 main menu
                            "./txts/001.txt",   //1 tutorial
                            "./txts/100.txt",   //2 ch1
                            "./txts/200.txt",   //3 ch2
                            "./txts/300.txt",   //4 ch3
                            "./txts/401.txt",   //5 goodend
                            "./txts/403.txt",   //6 badend
                            };
                            
char *chapter_filelist[] = {
                            "./txts/002.txt",   //0 tutorial
                            "./txts/101.txt",   //1 ch1
                            "./txts/201.txt",   //2 ch2
                            "./txts/202.txt",   //3
                            "./txts/203.txt",   //4
                            "./txts/301.txt",   //5 ch3
                            "./txts/302.txt",   //6
                            "./txts/303.txt",   //7
                            };
char *script_filelist[] = {
                            "./txts/003.txt",   //0 tutorial
                            "./txts/102.txt",   //ch1 1-3
                            "./txts/103.txt",
                            "./txts/104.txt",   //ch2 4-8
                            "./txts/204.txt",
                            "./txts/205.txt",   
                            "./txts/206.txt",
                            "./txts/207.txt",
                            "./txts/208.txt",
                            "./txts/304.txt",   //ch3 9-18
                            "./txts/305.txt",
                            "./txts/306.txt",
                            "./txts/307.txt",
                            "./txts/308.txt",
                            "./txts/309.txt",
                            "./txts/310.txt",
                            "./txts/311.txt",
                            "./txts/312.txt",
                            "./txts/313.txt",
                            };
char *ending_filelist[] = {
                            "./txts/400.txt",   //0 goodend
                            "./txts/402.txt",   //1 badend
                            };

int main() {
    startMenu();
    return 0;
}
//choice w/o forloop
void userChoice(){
    do {
    printf("\nChoose input: ");
    scanf("%d", &choice);
    calcScore(choice, &score);
    } while(choice>3 || choice<1);
}

//choice w/ for loop(tochange)
void scriptChoice(int i, int size){
    for(i; i < size; i++){
    wholeFile(script_filelist[i]);
    userChoice();
    getchar();
    }
}

//opens file line by line until user presses enter OK
void linebylineFile(char* file_to_open){
    FILE *playfile;
    char info[1000];

    playfile = fopen(file_to_open, "r");
   
    while(fgets(info, sizeof(info), playfile) != NULL) {
        printf("%s", info);
        fflush(stdin);
        getchar();
    };
    fclose(playfile);
}

//opens whole file OK
void wholeFile(char* file_to_open){
    FILE *playfile;
    char info[1000];

    playfile = fopen(file_to_open, "r");
    while(fgets(info, sizeof(info), playfile) != NULL) {
        printf("%s", info);
    };
    fclose(playfile);
}

//calcScore OK, remember to &score during function call
void calcScore(int choice, int *score) {
    switch(choice){
    case 1:
        *score+=5;
        printf("\n>> TEAM LEADER ALICE: Perfect! Keep it up! [...]\n");
        getchar();
        printf("Current score: %d\n", *score);
        break;
    case 2:
        printf("\n>> TEAM LEADER ALICE: Remember your job. make Ma'am SAM good! Anong ginawa mo?! [...]\n");
        getchar();
        printf("Current score: %d\n", *score);
        break;
    case 3:
        *score+=3;
        printf("\n>> TEAM LEADER ALICE: Good, but it could be better. [...]\n");
        getchar();
        printf("Current score: %d\n", *score);
        break;
    default:
        printf("invalid input. Try again\n");
        break;
    };  
}

//Quit Submenu OK
void quitSubmenu(){
    int choice, whileStop=1;
   
    printf("\nAre you sure?\n");
    printf("1. Yes\n"); 
    printf("2. No\n"); 
    
    while(whileStop){
    do{
        printf("\nChoose input: ");
        scanf("%d", &choice);
            switch(choice){
                case 1:
                    exit(0);
                    break;
                case 2:
                    whileStop=0;
                    break;
                default:
                    printf("Invalid input. Try again.\n");
                }
        } while(choice>2 || choice<1);
    }
}

//Game Start Menu OK
void startMenu()
{
    int whileStop=1;
    while(whileStop){
    wholeFile (header_filelist[0]);

    //User choice  
    do {
    printf("\nChoose input: ");
    scanf("%d", &choice);      
    switch(choice){
        case 1: 
            playGame();
            break;
        case 2:
            tutorialSubmenu();
            break;
        case 3:
            quitSubmenu();
            break;          
        default:
            printf("Invalid input. Try again.\n");   
            break;
        };
    } while(choice>3 || choice<1);
    }
}

//plays tutorial
void tutorialSubmenu(){
    wholeFile(header_filelist[1]);
    linebylineFile(chapter_filelist[0]);
    wholeFile(script_filelist[0]);
    userChoice();
    getchar();
    printf(">> TEAM LEADER ALICE: Trial lang 'to, ha? Later on, you'll tackle on far better things! [Press 'Enter' to go back]\n");
    score=0;
    getchar();
}

//play game
void playGame(){
    int a=2,b=1;
    //chapter 1
    i = 1, size = 4;
    wholeFile(header_filelist[2]);
    linebylineFile(chapter_filelist[1]);
    scriptChoice(i, size);
    printf("END OF CHAPTER 1");
    getchar();

    //chapter 2
    i = 4, size = 9;
    wholeFile(header_filelist[3]);
    if(score >=0 && score <=3)
        linebylineFile(chapter_filelist[3]);
    else if(score >= 3 && score <= 9)
        linebylineFile(chapter_filelist[4]);
    else
        linebylineFile(chapter_filelist[2]);
    scriptChoice(i, size);
    printf("END OF CHAPTER 2");
    getchar();

    //chapter 3
    i = 9, size = 19;
    wholeFile(header_filelist[4]);
    if(score >=0 && score <=8)
        linebylineFile(chapter_filelist[6]);
    else if(score>=9 && score<=24)
        linebylineFile(chapter_filelist[7]);
    else
        linebylineFile(chapter_filelist[5]);
    scriptChoice(i, size);
    printf("END OF CHAPTER 3");
    getchar();

    //ending
    if(score >=0 && score <=44){
        linebylineFile(ending_filelist[1]);
        wholeFile(header_filelist[6]);
    }
    else{
        linebylineFile(ending_filelist[0]);
        wholeFile(header_filelist[5]);
    } 
    getchar();
    printf("FINAL SCORE: %d\n", score);
    getchar();
    printf("1. Play again?\n");
    printf("2. Quit\n");

    do {
    printf("\nChoose input: ");
    scanf("%d", &choice);      
    switch(choice){
        case 1: 
            break;
        case 2:
            exit(0);
            break;          
        default:
            printf("Invalid input. Try again.\n");   
            break;
        };
    } while(choice>2 || choice<1);
    score = 0;
}