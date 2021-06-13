$NetBSD: patch-main_conversions.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/conversions.c.orig	2021-03-04 16:46:08.000000000 +0000
+++ main/conversions.c
@@ -37,7 +37,7 @@ static int str_is_negative(const char **
 	 * Ignore any preceding white space. It's okay to move the pointer here
 	 * since the converting function would do the same, i.e. skip white space.
 	 */
-	while (isspace(**str)) ++*str;
+	while (isspace((unsigned char)**str)) ++*str;
 	return **str == '-';
 }
 
