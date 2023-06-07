$NetBSD: patch-libavformat_avformat.h,v 1.1 2023/06/07 11:42:47 markd Exp $

expose av_stream_get_first_dts() for chromium - from ArchLinux

--- libavformat/avformat.h.orig	2023-02-27 20:43:45.000000000 +0000
+++ libavformat/avformat.h
@@ -1019,6 +1019,10 @@ attribute_deprecated
 int64_t    av_stream_get_end_pts(const AVStream *st);
 #endif
 
+// Chromium: We use the internal field first_dts vvv
+int64_t    av_stream_get_first_dts(const AVStream *st);
+// Chromium: We use the internal field first_dts ^^^
+
 #define AV_PROGRAM_RUNNING 1
 
 /**
