$NetBSD: patch-contrib_zip_src_zip.h,v 1.4 2024/07/04 06:15:32 adam Exp $

Fix builds on some 32-bit architectures.

--- contrib/zip/src/zip.h.orig	2024-07-03 19:37:24.000000000 +0000
+++ contrib/zip/src/zip.h
@@ -34,15 +34,6 @@
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
 
 /**
  * @mainpage
