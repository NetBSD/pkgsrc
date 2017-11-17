$NetBSD: patch-ext_libav_gstavviddec.c,v 1.1 2017/11/17 23:21:06 prlw1 Exp $

"quick & dirty hack to use new decoding API for viddec" from
https://bugzilla.gnome.org/show_bug.cgi?id=789193

--- ext/libav/gstavviddec.c.orig	2017-08-10 15:56:34.000000000 +0000
+++ ext/libav/gstavviddec.c
@@ -1525,8 +1525,20 @@ gst_ffmpegviddec_video_frame (GstFFMpegV
    * See https://bugzilla.gnome.org/show_bug.cgi?id=726020
    */
   GST_VIDEO_DECODER_STREAM_UNLOCK (ffmpegdec);
-  len = avcodec_decode_video2 (ffmpegdec->context,
-      ffmpegdec->picture, have_data, &packet);
+  *have_data = 0;
+  if (size > 0) {
+    len = avcodec_send_packet(ffmpegdec->context, &packet);
+    if (len == AVERROR(EAGAIN)) {
+      len = 0;
+    } else {
+      len = size;
+    }
+    if (len >= 0) {
+      int result = avcodec_receive_frame(ffmpegdec->context, ffmpegdec->picture);
+      if (result == 0)
+        *have_data = 1;
+    }
+  }
   GST_VIDEO_DECODER_STREAM_LOCK (ffmpegdec);
 
   GST_DEBUG_OBJECT (ffmpegdec, "after decode: len %d, have_data %d",
