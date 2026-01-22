$NetBSD: patch-media_libpng_pngpriv.h,v 1.5 2026/01/22 19:41:09 ryoon Exp $

Fix _POSIX_SOURCE on SunOS.

--- media/libpng/pngpriv.h.orig	2025-12-31 13:17:28.000000000 +0000
+++ media/libpng/pngpriv.h
@@ -47,7 +47,9 @@
  * still required (as of 2011-05-02.)
  */
 #ifndef _POSIX_SOURCE
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #  define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
+#endif
 #endif
 
 #ifndef PNG_VERSION_INFO_ONLY
