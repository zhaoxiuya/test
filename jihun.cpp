#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct coord{
    int x, y;
};

int pan[1010][1010]={0,};
coord d[4]={{1,0},{-1,0},{0,1},{0,-1}}, lim;

void dfs(coord now){
    coord next;
    pan[now.x][now.y]=0;
    for(auto D: d){
        next={now.x+D.x, now.y+D.y};
        if(0<=next.x&&next.x<lim.x&&0<=next.y&&next.y<lim.y){
            if(pan[next.x][next.y]==1){
                // pan[next.x][next.y]=0;
                dfs(next);
            }
        }
    }
}

int main(void){
    int tmp=0, ctv=0, cnt=0;
    scanf("%d %d", &lim.x, &lim.y);
    for(int i=0; i<lim.x; i++){
        for(int j=0; j<lim.y; j++){
            for(int k=0; k<3; k++){
                scanf("%d", &tmp);
                pan[i][j]+=tmp;
            }
        }
    }
    scanf("%d", &ctv);
    for(int i=0; i<lim.x; i++){
        for(int j=0; j<lim.y; j++){
            pan[i][j]=ctv*3<=pan[i][j]? 1: 0;
        }
    }
    for(int i=0; i<lim.x; i++){
        for(int j=0; j<lim.y; j++){
            if(pan[i][j]==1){
                cnt++;
                dfs({i, j});
            }
        }
    }
    printf("%d", cnt);
}