$NetBSD: patch-lib_bashline.c,v 1.1 2014/04/17 20:27:32 joerg Exp $

--- lib/bashline.c.orig	2014-04-17 18:30:42.000000000 +0000
+++ lib/bashline.c
@@ -41,7 +41,7 @@ static int completion_quoting_style = CO
 /* A function to strip quotes that are not protected by backquotes.  It
    allows single quotes to appear within double quotes, and vice versa.
    It should be smarter. */
-char *bash_dequote_filename (const char *text, int quote_char)
+char *bash_dequote_filename (char *text, int quote_char)
 {
 	char *ret, *r;
 	const char *p;
