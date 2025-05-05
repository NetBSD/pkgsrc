$NetBSD: patch-src_lexer.c,v 1.1 2025/05/05 14:52:00 wiz Exp $

Fix invalid ctype(3) arguments.
https://github.com/libconfuse/libconfuse/issues/180

--- src/lexer.c.orig	2025-05-05 14:42:07.813521101 +0000
+++ src/lexer.c
@@ -2662,14 +2662,14 @@ static char *trim_whitespace(char *str, 
 	return str;
 
     while (len > 1) {
-	if ((str[len] == 0 || isspace(str[len])) && isspace(str[len - 1]))
+	if ((str[len] == 0 || isspace((unsigned char)str[len])) && isspace((unsigned char)str[len - 1]))
 	    len--;
 	else
 	    break;
     }
     str[len] = 0;
 
-    while (isspace(*str))
+    while (isspace((unsigned char)*str))
 	str++;
 
     return str;
