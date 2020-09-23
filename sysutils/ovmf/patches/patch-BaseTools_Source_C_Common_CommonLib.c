$NetBSD: patch-BaseTools_Source_C_Common_CommonLib.c,v 1.3 2020/09/23 11:23:38 prlw1 Exp $

error: array subscript has type 'char' [-Werror=char-subscripts]

--- BaseTools/Source/C/Common/CommonLib.c.orig	2019-01-10 14:18:56.000000000 +0000
+++ BaseTools/Source/C/Common/CommonLib.c
@@ -582,7 +582,7 @@ char *strlwr(char *s)
 {
   char *p = s;
   for(;*s;s++) {
-    *s = tolower(*s);
+    *s = tolower((unsigned char)*s);
   }
   return p;
 }
