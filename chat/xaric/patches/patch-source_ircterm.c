$NetBSD: patch-source_ircterm.c,v 1.2 2013/07/21 11:29:55 shattered Exp $

--- ircterm.c.orig	2010-01-09 09:26:08.000000000 +0000
+++ ircterm.c
@@ -97,10 +97,12 @@ static int term_LE_cursor_left(void);
 static int term_null_function(void);
 
 /* these are missing on some systems */
+#ifndef __sun
 extern char *tgetstr();
 extern int tgetent();
 extern char *getenv();
 extern char *tgoto(const char *, int, int);
+#endif
 
 /* Setup the low level terminal disipline */
 static void setup_tty(void)
