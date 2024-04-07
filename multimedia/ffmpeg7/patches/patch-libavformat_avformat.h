$NetBSD: patch-libavformat_avformat.h,v 1.1 2024/04/07 17:50:24 ryoon Exp $

expose av_stream_get_first_dts() for chromium - from ArchLinux

--- libavformat/avformat.h.orig	2024-04-04 23:23:00.000000000 +0000
+++ libavformat/avformat.h
@@ -1170,6 +1170,10 @@ typedef struct AVStreamGroup {
 
 struct AVCodecParserContext *av_stream_get_parser(const AVStream *s);
 
+// Chromium: We use the internal field first_dts vvv
+int64_t	av_stream_get_first_dts(const AVStream *st);
+// Chromium: We use the internal field first_dts ^^^
+
 #define AV_PROGRAM_RUNNING 1
 
 /**
