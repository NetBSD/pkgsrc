$NetBSD: patch-sl.c,v 1.1 2024/11/10 16:23:49 bsiegert Exp $

Put terminal into a known state. Do not write characters exceeding COLS.

--- sl.c.orig	2024-11-10 16:18:40.738913492 +0000
+++ sl.c
@@ -58,7 +58,7 @@ int my_mvaddstr(int y, int x, char *str)
 {
     for ( ; x < 0; ++x, ++str)
         if (*str == '\0')  return ERR;
-    for ( ; *str != '\0'; ++str, ++x)
+    for ( ; *str != '\0' && x < COLS; ++str, ++x)
         if (mvaddch(y, x, *str) == ERR)  return ERR;
     return OK;
 }
@@ -89,6 +89,7 @@ int main(int argc, char *argv[])
     }
     initscr();
     signal(SIGINT, SIG_IGN);
+    cbreak();
     noecho();
     curs_set(0);
     nodelay(stdscr, TRUE);
