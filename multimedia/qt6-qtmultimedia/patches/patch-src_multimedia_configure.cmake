$NetBSD: patch-src_multimedia_configure.cmake,v 1.1 2024/04/01 13:40:27 adam Exp $

Make GStreamer available not only for Linux.

--- src/multimedia/configure.cmake.orig	2024-03-28 20:25:19.900829538 +0000
+++ src/multimedia/configure.cmake
@@ -101,7 +101,7 @@ qt_feature("evr" PUBLIC PRIVATE
 )
 qt_feature("gstreamer_1_0" PRIVATE
     LABEL "GStreamer 1.0"
-    CONDITION ( LINUX AND GStreamer_FOUND )
+    CONDITION GStreamer_FOUND
     ENABLE INPUT_gstreamer STREQUAL 'yes'
     DISABLE INPUT_gstreamer STREQUAL 'no'
 )
