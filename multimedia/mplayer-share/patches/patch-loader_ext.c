$NetBSD: patch-loader_ext.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- loader/ext.c.orig	2025-10-08 03:33:12.124808527 +0000
+++ loader/ext.c
@@ -168,7 +168,7 @@ int wcsnicmp(const unsigned short* s1, c
     */
     while(n>0)
     {
-	if (((*s1 | *s2) & 0xff00) || toupper((char)*s1) != toupper((char)*s2))
+	if (((*s1 | *s2) & 0xff00) || toupper((unsigned char)*s1) != toupper((unsigned char)*s2))
 	{
 
 	    if(*s1<*s2)
