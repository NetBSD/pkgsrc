$NetBSD: patch-libavformat_mux__utils.c,v 1.1 2023/06/07 11:42:21 markd Exp $

expose av_stream_get_first_dts() for chromium - from ArchLinux

--- libavformat/mux_utils.c.orig	2023-03-26 14:21:00.000000000 +0000
+++ libavformat/mux_utils.c
@@ -37,6 +37,13 @@ int64_t av_stream_get_end_pts(const AVSt
         return AV_NOPTS_VALUE;
 }
 
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
