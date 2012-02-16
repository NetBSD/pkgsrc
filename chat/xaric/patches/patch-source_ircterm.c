$NetBSD: patch-source_ircterm.c,v 1.1 2012/02/16 16:13:51 hans Exp $

--- source/ircterm.c.orig	2001-11-24 09:07:57.000000000 +0100
+++ source/ircterm.c	2012-01-24 20:14:53.277926058 +0100
@@ -99,10 +99,12 @@ static int term_LE_cursor_left (void);
 static int term_null_function (void);
 
 /* these are missing on some systems */
+#ifndef __sun
 extern char *tgetstr ();
 extern int tgetent ();
 extern char *getenv ();
 extern char *tgoto(const char *, int, int);
+#endif
 
 
 /* Setup the low level terminal disipline */
