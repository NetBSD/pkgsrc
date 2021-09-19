$NetBSD: patch-libraw_libraw__const.h,v 1.1 2021/09/19 18:46:50 nia Exp $

Thumbnail size range check (CVE-2020-15503)

--- libraw/libraw_const.h.orig	2019-08-20 17:34:30.000000000 +0000
+++ libraw/libraw_const.h
@@ -24,6 +24,11 @@ it under the terms of the one of two lic
 #define LIBRAW_MAX_ALLOC_MB 2048L
 #endif
 
+/* limit thumbnail size, default is 512Mb*/
+#ifndef LIBRAW_MAX_THUMBNAIL_MB
+#define LIBRAW_MAX_THUMBNAIL_MB 512L
+#endif
+
 /* Change to non-zero to allow (broken) CRW (and other) files metadata 
    loop prevention */
 #ifndef LIBRAW_METADATA_LOOP_PREVENTION
