$NetBSD: patch-mozilla_media_libpng_pngpriv.h,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/media/libpng/pngpriv.h.orig	2016-04-07 21:33:21.000000000 +0000
+++ mozilla/media/libpng/pngpriv.h
@@ -36,6 +36,7 @@
  * still required (as of 2011-05-02.)
  */
 #define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
+#define _XOPEN_SOURCE 600
 
 #ifndef PNG_VERSION_INFO_ONLY
 /* Standard library headers not required by png.h: */
