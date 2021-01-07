$NetBSD: patch-contrib_zip_src_zip.h,v 1.1 2021/01/07 05:15:47 gutteridge Exp $

Fix builds on some 32-bit architectures.

--- contrib/zip/src/zip.h.orig	2020-01-12 11:56:40.000000000 +0000
+++ contrib/zip/src/zip.h
@@ -21,13 +21,14 @@ extern "C" {
 
 #if !defined(_SSIZE_T_DEFINED) && !defined(_SSIZE_T_DEFINED_) &&               \
     !defined(_SSIZE_T) && !defined(_SSIZE_T_) && !defined(__ssize_t_defined)
-#define _SSIZE_T
+//#define _SSIZE_T
 // 64-bit Windows is the only mainstream platform
 // where sizeof(long) != sizeof(void*)
 #ifdef _WIN64
+#define _SSIZE_T
 typedef long long  ssize_t;  /* byte count or error */
-#else
-typedef long  ssize_t;  /* byte count or error */
+//#else
+//typedef long  ssize_t;  /* byte count or error */
 #endif
 #endif
 
