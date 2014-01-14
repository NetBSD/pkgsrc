$NetBSD: patch-src_console_conio.c,v 1.2 2014/01/14 10:58:17 markd Exp $

- need termios.h, our term.h does not include it
- t_insert_line and t_delete_line are macros in term.h; undef them

--- src/console/conio.c.orig	2013-02-19 19:21:35.000000000 +0000
+++ src/console/conio.c
@@ -64,6 +64,7 @@
 
 #ifdef HAVE_CONIO
 
+#include <termios.h>
 #include <curses.h>
 #include <term.h>
 
@@ -250,7 +251,9 @@ static char * getnext(void);
 static char * getprev(void);
 static void putline(char *newl, int newlen);
 static void t_honk_horn(void);
+#undef t_insert_line
 static void t_insert_line(void);
+#undef t_delete_line
 static void t_delete_line(void);
 static void t_clrline(int pos, int width);
 void t_sendl(const char *msg, int len);
