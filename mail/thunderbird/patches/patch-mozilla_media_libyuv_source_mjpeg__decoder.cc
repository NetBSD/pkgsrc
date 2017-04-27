$NetBSD: patch-mozilla_media_libyuv_source_mjpeg__decoder.cc,v 1.1 2017/04/27 13:32:41 ryoon Exp $

--- mozilla/media/libyuv/source/mjpeg_decoder.cc.orig	2017-04-14 04:53:19.000000000 +0000
+++ mozilla/media/libyuv/source/mjpeg_decoder.cc
@@ -25,7 +25,6 @@
 #endif
 
 #endif
-struct FILE;  // For jpeglib.h.
 
 // C++ build requires extern C for jpeg internals.
 #ifdef __cplusplus
