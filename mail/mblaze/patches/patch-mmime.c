$NetBSD: patch-mmime.c,v 1.1 2026/10/15 19:44:23 ktnb Exp $

NetBSD 11 ctype fix.

--- mmime.c.orig	2026-10-15 19:39:38.696179634 +0000
+++ mmime.c
@@ -404,7 +404,7 @@ valid_content_type(char *s)
 	for (; *s; s++)
 		if (*s == '/')
 			slash++;
-		else if (isalnum(*s) || *s == '-' || *s == '+' || *s == '.' ||
+		else if (isalnum((unsigned char)*s) || *s == '-' || *s == '+' || *s == '.' ||
 		    *s == ';' || *s == '=' || *s == '#')
 			; /* ok */
 		else
