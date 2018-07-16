$NetBSD: patch-main_conversions.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- main/conversions.c.orig	2018-05-07 17:26:43.897798394 +0000
+++ main/conversions.c
@@ -33,7 +33,7 @@
 static int str_is_negative(const char *str)
 {
 	/* Ignore any preceding white space */
-	while (isspace(*str) && *++str);
+	while (isspace((unsigned char)*str) && *++str);
 	return *str == '-';
 }
 
