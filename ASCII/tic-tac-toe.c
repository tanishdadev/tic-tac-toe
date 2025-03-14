#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int getFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
    char winner = ' ';
    char response = ' ';

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();
    
        while(winner == ' ' && getFreeSpaces() != 0){
            printBoard();
            playerMove();
    
            winner = checkWinner();
            if(winner != ' ' || getFreeSpaces() == 0){
                break;
            }
    
            computerMove();
    
            winner = checkWinner();
            if(winner != ' ' || getFreeSpaces() == 0){
                break;
            }
        }
        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("Thanks for playing!");

    return 0;
}

void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
    printf("\n");
}
int getFreeSpaces(){
    int freespaces = 9;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                freespaces--;
            }
        }
    }
    return freespaces;
}
void playerMove(){
    int x;
    int y;

    do
    {
        printf("Enter the row number #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter the column number #(1-3): ");
        scanf("%d", &y);
        y--;
    
        if(board[y][x] != ' '){
            printf("Invalid move");
        }
        else{
            board[y][x] = PLAYER;
            break;
        }
    } while (board[y][x] != ' ');
    
}
void computerMove(){
    srand(time(0));
    int x;
    int y;
    
    if(getFreeSpaces() > 0){
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else{
        printBoard(' ');
    }
}
char checkWinner(){
    // rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    // columns
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    // diagnols
    for(int i = 0; i < 3; i++){
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            return board[0][0];
        }
    }
    for(int i = 0; i < 3; i++){
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
            return board[0][2];
        }
    }
    return ' ';
}
void printWinner(char winner){
    if(winner == PLAYER){
        printf("YOU WIN!");
    }
    else if(winner == COMPUTER){
        printf("COMPUTER WINS!");
    }
    else{
        printf("ITS A TIE!");
    }
}