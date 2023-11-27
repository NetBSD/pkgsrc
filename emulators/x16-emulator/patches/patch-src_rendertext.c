$NetBSD: patch-src_rendertext.c,v 1.2 2023/11/27 04:17:30 thorpej Exp $

Safely pass a char to ctype(3) functions.

--- src/rendertext.c.orig	2022-08-07 02:20:35.066620319 +0000
+++ src/rendertext.c	2022-08-07 02:22:17.485680282 +0000
@@ -23,7 +23,7 @@ int textureInitialized = 0;
 //
 char *ltrim(char *s)
 {
-	while(isspace(*s)) s++;
+	while(isspace((unsigned char)*s)) s++;
 	return s;
 }
 
