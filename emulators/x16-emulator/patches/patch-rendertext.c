$NetBSD: patch-rendertext.c,v 1.1 2020/04/18 22:04:18 joerg Exp $

--- rendertext.c.orig	2020-04-17 21:39:18.771500194 +0000
+++ rendertext.c
@@ -22,7 +22,7 @@ int textureInitialized = 0;
 //
 char *ltrim(char *s)
 {
-	while(isspace(*s)) s++;
+	while(isspace((unsigned char)*s)) s++;
 	return s;
 }
 
