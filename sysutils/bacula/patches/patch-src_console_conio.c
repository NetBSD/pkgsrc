$NetBSD: patch-src_console_conio.c,v 1.1 2012/10/06 17:54:53 christos Exp $

- need termios.h, our term.h does not include it
- t_insert_line and t_delete_line are macros in term.h; undef them

--- src/console/conio.c.orig	2012-09-13 04:51:19.000000000 -0400
+++ src/console/conio.c	2012-10-05 11:29:38.000000000 -0400
@@ -61,6 +61,7 @@
 
 #endif
 
+#include <termios.h>
 #include <curses.h>
 #include <term.h>
 
@@ -245,7 +246,9 @@
 static char * getprev(void);
 static void putline(char *newl, int newlen);
 static void t_honk_horn(void);
+#undef t_insert_line
 static void t_insert_line(void);
+#undef t_delete_line
 static void t_delete_line(void);
 static void t_clrline(int pos, int width);
 void t_sendl(const char *msg, int len);
