$NetBSD: patch-libavformat_mux__utils.c,v 1.1 2024/04/07 17:50:24 ryoon Exp $

expose av_stream_get_first_dts() for chromium - from ArchLinux

--- libavformat/mux_utils.c.orig	2024-04-04 23:23:00.000000000 +0000
+++ libavformat/mux_utils.c
@@ -30,6 +30,13 @@
 #include "internal.h"
 #include "mux.h"
 
+// Chromium: We use the internal field first_dts vvv
+int64_t av_stream_get_first_dts(const AVStream *st)
+{
+  return cffstream(st)->first_dts;
+}
+// Chromium: We use the internal field first_dts ^^^
+
 int avformat_query_codec(const AVOutputFormat *ofmt, enum AVCodecID codec_id,
                          int std_compliance)
 {
