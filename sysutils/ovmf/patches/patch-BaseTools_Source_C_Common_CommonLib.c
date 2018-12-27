$NetBSD: patch-BaseTools_Source_C_Common_CommonLib.c,v 1.1 2018/12/27 15:12:36 joerg Exp $

--- BaseTools/Source/C/Common/CommonLib.c.orig	2018-12-25 23:50:04.866006429 +0000
+++ BaseTools/Source/C/Common/CommonLib.c
@@ -574,7 +574,7 @@ char *strlwr(char *s)
 {
   char *p = s;
   for(;*s;s++) {
-    *s = tolower(*s);
+    *s = tolower((unsigned char)*s);
   }
   return p;
 }
