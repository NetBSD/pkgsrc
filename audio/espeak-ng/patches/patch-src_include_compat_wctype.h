$NetBSD: patch-src_include_compat_wctype.h,v 1.1 2024/03/25 17:18:08 jperkin Exp $

Avoid breaking wctypes on illumos.

--- src/include/compat/wctype.h.orig	2024-03-25 17:06:14.205256009 +0000
+++ src/include/compat/wctype.h
@@ -32,6 +32,7 @@
 
 #include <ucd/ucd.h>
 
+#if !defined(__illumos__)
 #define iswalnum  ucd_isalnum
 #define iswalpha  ucd_isalpha
 #define iswblank  ucd_isblank
@@ -44,5 +45,6 @@
 #define iswspace  ucd_isspace
 #define iswupper  ucd_isupper
 #define iswxdigit ucd_isxdigit
+#endif
 
 #endif
