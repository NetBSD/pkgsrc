$NetBSD: patch-libavformat_avformat.h,v 1.1 2023/06/07 11:42:21 markd Exp $

expose av_stream_get_first_dts() for chromium - from ArchLinux

--- libavformat/avformat.h.orig	2023-03-26 14:21:00.000000000 +0000
+++ libavformat/avformat.h
@@ -1128,6 +1128,10 @@ struct AVCodecParserContext *av_stream_g
  */
 int64_t    av_stream_get_end_pts(const AVStream *st);
 
+// Chromium: We use the internal field first_dts vvv
+int64_t    av_stream_get_first_dts(const AVStream *st);
+// Chromium: We use the internal field first_dts ^^^
+
 #define AV_PROGRAM_RUNNING 1
 
 /**
