$NetBSD: patch-src_third-party_zip_zip.h,v 1.1 2024/10/02 06:51:35 nia Exp $

Do not perform games with defining our own ssize_t, the compiler
may decide it's incompatible with the already-defined version.

--- src/third-party/zip/zip.h.orig	2024-10-02 06:48:53.624920629 +0000
+++ src/third-party/zip/zip.h
@@ -12,6 +12,7 @@
 #ifndef ZIP_H
 #define ZIP_H
 
+#include <stddef.h>
 #include <string.h>
 #include <sys/types.h>
 
@@ -19,18 +20,6 @@
 extern "C" {
 #endif
 
-#if !defined(_SSIZE_T_DEFINED) && !defined(_SSIZE_T_DEFINED_) &&               \
-    !defined(_SSIZE_T) && !defined(_SSIZE_T_) && !defined(__ssize_t_defined)
-#define _SSIZE_T
-// 64-bit Windows is the only mainstream platform
-// where sizeof(long) != sizeof(void*)
-#ifdef _WIN64
-typedef long long  ssize_t;  /* byte count or error */
-#else
-typedef long  ssize_t;  /* byte count or error */
-#endif
-#endif
-
 #ifndef MAX_PATH
 #define MAX_PATH 32767 /* # chars in a path name including NULL */
 #endif
