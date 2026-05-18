$NetBSD: patch-cbonsai.c,v 1.1 2026/05/18 12:20:36 nia Exp $

Support for NetBSD curses and wcwidth(3) visibility.

https://gitlab.com/jallbrit/cbonsai/-/merge_requests/26

--- cbonsai.c.orig	2025-06-20 02:28:16.000000000 +0000
+++ cbonsai.c
@@ -1,5 +1,5 @@
 #ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE 500
+#define _XOPEN_SOURCE 600
 #endif
 
 #include <stdlib.h>
@@ -643,7 +643,6 @@ void init(const struct config *conf, struct ncursesObj
 }
 
 void init(const struct config *conf, struct ncursesObjects *objects) {
-	savetty();	// save terminal settings
 	initscr();	// init ncurses screen
 	noecho();	// don't echo input to screen
 	curs_set(0);	// make cursor invisible
