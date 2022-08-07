$NetBSD: patch-src_rendertext.c,v 1.1 2022/08/07 17:38:08 thorpej Exp $

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
 
