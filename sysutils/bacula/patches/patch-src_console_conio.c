$NetBSD: patch-src_console_conio.c,v 1.3 2014/01/22 10:45:21 jperkin Exp $

- need termios.h, our term.h does not include it
- t_insert_line and t_delete_line are macros in term.h; undef them
- spell HAVE_TERM_H correctly

--- src/console/conio.c.orig	2013-02-19 19:21:35.000000000 +0000
+++ src/console/conio.c
@@ -64,11 +64,12 @@
 
 #ifdef HAVE_CONIO
 
+#include <termios.h>
 #include <curses.h>
 #include <term.h>
 
 #if defined(HAVE_SUN_OS)
-#if !defined(_TERM_H)
+#if !defined(HAVE_TERM_H)
 extern "C" int tgetent(void *, const char *);
 extern "C" int tgetnum(const char *);
 extern "C" char *tgetstr (const char*, char**);
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
