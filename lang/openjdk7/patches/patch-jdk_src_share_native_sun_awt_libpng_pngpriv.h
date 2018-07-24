$NetBSD: patch-jdk_src_share_native_sun_awt_libpng_pngpriv.h,v 1.1 2018/07/24 16:07:25 jperkin Exp $

Fix build on SunOS with C99.

--- jdk/src/share/native/sun/awt/libpng/pngpriv.h.orig	2017-08-13 05:55:19.000000000 +0000
+++ jdk/src/share/native/sun/awt/libpng/pngpriv.h
@@ -63,7 +63,9 @@
  * Windows/Visual Studio) there is no effect; the OS specific tests below are
  * still required (as of 2011-05-02.)
  */
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
+#endif
 
 #ifndef PNG_VERSION_INFO_ONLY
 /* Standard library headers not required by png.h: */
