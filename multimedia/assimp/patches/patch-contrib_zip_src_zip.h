$NetBSD: patch-contrib_zip_src_zip.h,v 1.3 2022/04/14 13:20:42 nros Exp $

Fix builds on some 32-bit architectures.

--- contrib/zip/src/zip.h.orig	2022-03-17 10:35:44.000000000 +0000
+++ contrib/zip/src/zip.h
@@ -19,16 +19,6 @@
 extern "C" {
 #endif
 
-#if !defined(_POSIX_C_SOURCE) && defined(_MSC_VER)
-// 64-bit Windows is the only mainstream platform
-// where sizeof(long) != sizeof(void*)
-#ifdef _WIN64
-typedef long long ssize_t; /* byte count or error */
-#else
-typedef long ssize_t; /* byte count or error */
-#endif
-#endif
-
 #ifndef MAX_PATH
 #define MAX_PATH 32767 /* # chars in a path name including NULL */
 #endif
