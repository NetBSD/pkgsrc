$NetBSD: patch-media_libpng_pngpriv.h,v 1.4 2020/03/13 17:59:27 wiz Exp $

Fix _POSIX_SOURCE on SunOS.

--- media/libpng/pngpriv.h.orig	2018-06-05 19:47:32.000000000 +0000
+++ media/libpng/pngpriv.h
@@ -36,8 +36,10 @@
  * still required (as of 2011-05-02.)
  */
 #ifndef _POSIX_SOURCE
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 # define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
 #endif
+#endif
 
 #ifndef PNG_VERSION_INFO_ONLY
 /* Standard library headers not required by png.h: */
