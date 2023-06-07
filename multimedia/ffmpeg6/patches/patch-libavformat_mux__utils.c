$NetBSD: patch-libavformat_mux__utils.c,v 1.1 2023/06/07 11:42:47 markd Exp $

expose av_stream_get_first_dts() for chromium - from ArchLinux

--- libavformat/mux_utils.c.orig	2023-02-27 20:43:45.000000000 +0000
+++ libavformat/mux_utils.c
@@ -40,6 +40,13 @@ int64_t av_stream_get_end_pts(const AVSt
 }
 #endif
 
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
