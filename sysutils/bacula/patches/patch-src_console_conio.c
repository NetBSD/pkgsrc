$NetBSD: patch-src_console_conio.c,v 1.4 2019/02/07 11:29:31 markd Exp $

- need termios.h, our term.h does not include it
- t_insert_line and t_delete_line are macros in term.h; undef them
- spell HAVE_TERM_H correctly

--- src/console/conio.c.orig	2018-12-21 08:40:51.000000000 +0000
+++ src/console/conio.c
@@ -54,11 +54,12 @@
 
 #ifdef HAVE_CONIO
 
+#include <termios.h>
 #include <curses.h>
 #include <term.h>
 
 #ifdef HAVE_SUN_OS
-#ifndef _TERM_H
+#ifndef HAVE_TERM_H
 extern "C" int tgetent(void *, const char *);
 extern "C" int tgetnum(const char *);
 extern "C" char *tgetstr (const char*, char**);
@@ -235,7 +236,9 @@ static char * getnext(void);
 static char * getprev(void);
 static void putline(char *newl, int newlen);
 static void t_honk_horn(void);
+#undef t_insert_line
 static void t_insert_line(void);
+#undef t_delete_line
 static void t_delete_line(void);
 static void t_clrline(int pos, int width);
 void t_sendl(const char *msg, int len);
