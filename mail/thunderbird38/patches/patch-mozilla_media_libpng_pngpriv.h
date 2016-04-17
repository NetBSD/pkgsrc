$NetBSD: patch-mozilla_media_libpng_pngpriv.h,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/media/libpng/pngpriv.h.orig	2014-07-18 00:05:38.000000000 +0000
+++ mozilla/media/libpng/pngpriv.h
@@ -38,6 +38,7 @@
  * still required (as of 2011-05-02.)
  */
 #define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
+#define _XOPEN_SOURCE 600
 
 #ifndef PNG_VERSION_INFO_ONLY
 /* Standard library headers not required by png.h: */
