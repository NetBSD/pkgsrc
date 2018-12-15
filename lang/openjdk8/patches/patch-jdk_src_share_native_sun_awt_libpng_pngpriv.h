$NetBSD: patch-jdk_src_share_native_sun_awt_libpng_pngpriv.h,v 1.3 2018/12/15 20:27:45 jperkin Exp $

Set _POSIX_SOURCE correctly.

--- jdk/src/share/native/sun/awt/libpng/pngpriv.h.orig	2018-12-09 09:51:37.000000000 +0000
+++ jdk/src/share/native/sun/awt/libpng/pngpriv.h
@@ -63,7 +63,7 @@
  * Windows/Visual Studio) there is no effect; the OS specific tests below are
  * still required (as of 2011-05-02.)
  */
-#ifndef _POSIX_SOURCE
+#if (!defined(__sun) || (__STDC_VERSION__-0 < 199901L)) && !defined(_POSIX_SOURCE)
 # define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
 #endif
 
