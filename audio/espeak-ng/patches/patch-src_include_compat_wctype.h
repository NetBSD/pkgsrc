$NetBSD: patch-src_include_compat_wctype.h,v 1.2 2024/12/26 11:45:00 wiz Exp $

Avoid breaking wctypes on illumos.

--- src/include/compat/wctype.h.orig	2024-12-12 13:28:01.000000000 +0000
+++ src/include/compat/wctype.h
@@ -32,6 +32,7 @@
 
 #include <ucd/ucd.h>
 
+#if !defined(__illumos__)
 #define iswalnum  ucd_isalnum
 #define iswalpha  ucd_isalpha
 #define iswblank  ucd_isblank
@@ -44,6 +45,7 @@
 #define iswspace  ucd_isspace
 #define iswupper  ucd_isupper
 #define iswxdigit ucd_isxdigit
 #define tolower ucd_tolower
 #define toupper udc_toupper
+#endif
 
