$NetBSD: patch-jdk_src_share_native_sun_awt_libpng_pngpriv.h,v 1.4 2026/02/01 06:50:58 ryoon Exp $

Set _POSIX_SOURCE correctly.

--- jdk/src/share/native/sun/awt/libpng/pngpriv.h.orig	2026-01-23 00:36:25.000000000 +0000
+++ jdk/src/share/native/sun/awt/libpng/pngpriv.h
@@ -75,7 +75,7 @@
  * Windows/Visual Studio) there is no effect; the OS specific tests below are
  * still required (as of 2011-05-02.)
  */
-#ifndef _POSIX_SOURCE
+#if (!defined(__sun) || (__STDC_VERSION__-0 < 199901L)) && !defined(_POSIX_SOURCE)
 #  define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
 #endif
 
