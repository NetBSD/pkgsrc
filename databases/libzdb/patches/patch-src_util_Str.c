$NetBSD: patch-src_util_Str.c,v 1.1 2022/10/28 18:25:01 he Exp $

Cast arg to toupper() to u_char, to avoid domain error.

--- src/util/Str.c.orig	2019-05-30 22:22:30.000000000 +0000
+++ src/util/Str.c
@@ -50,7 +50,8 @@
 bool Str_isEqual(const char *a, const char *b) {
 	if (a && b) { 
                 while (*a && *b)
-                        if (toupper(*a++) != toupper(*b++)) return false;
+                        if (toupper((u_char)*a++) != toupper((u_char)*b++))
+				return false;
                 return (*a == *b);
         }
         return false;
