$NetBSD: patch-src_curses__client_curses__client.c,v 1.1 2021/01/26 22:12:08 fcambus Exp $

--- src/curses_client/curses_client.c.orig	2021-01-03 12:38:52.113243136 +0000
+++ src/curses_client/curses_client.c
@@ -45,7 +45,6 @@
 #include "tstring.h"
 
 static int ResizedFlag;
-static SCREEN *cur_screen;
 
 #define PromptAttr   (COLOR_PAIR(1))
 #define TextAttr     (COLOR_PAIR(2))
@@ -113,7 +112,7 @@ static gboolean QuitRequest, WantColor =
  */
 static void start_curses(void)
 {
-  cur_screen = newterm(NULL, stdout, stdin);
+  initscr();
   if (WantColor) {
     start_color();
     init_pair(1, COLOR_MAGENTA, COLOR_WHITE);
