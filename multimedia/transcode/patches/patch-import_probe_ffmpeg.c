$NetBSD: patch-import_probe_ffmpeg.c,v 1.3 2019/12/29 10:23:53 markd Exp $

Fixes building against FFmpeg version >= 4.0.0 (gentoo patch).

--- import/probe_ffmpeg.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ import/probe_ffmpeg.c
@@ -51,8 +51,8 @@ static void translate_info(const AVForma
             info->bitrate = st->codec->bit_rate / 1000;
             info->width = st->codec->width;
             info->height = st->codec->height;
-            if (st->r_frame_rate.num > 0 && st->r_frame_rate.den > 0) {
-                info->fps = av_q2d(st->r_frame_rate);
+            if (st->avg_frame_rate.num > 0 && st->avg_frame_rate.den > 0) {
+                info->fps = av_q2d(st->avg_frame_rate);
             } else {
                 /* watch out here */
                 info->fps = 1.0/av_q2d(st->codec->time_base);
@@ -99,8 +99,8 @@ void probe_ffmpeg(info_t *ipipe)
 
     TC_INIT_LIBAVCODEC;
 
-    ret = av_open_input_file(&lavf_dmx_context, ipipe->name,
-                             NULL, 0, NULL);
+    ret = avformat_open_input(&lavf_dmx_context, ipipe->name,
+                             NULL, NULL);
     if (ret != 0) {
         tc_log_error(__FILE__, "unable to open '%s'"
                                " (libavformat failure)",
@@ -109,7 +109,7 @@ void probe_ffmpeg(info_t *ipipe)
         return;
     }
 
-    ret = av_find_stream_info(lavf_dmx_context);
+    ret = avformat_find_stream_info(lavf_dmx_context, NULL);
     if (ret < 0) {
         tc_log_error(__FILE__, "unable to fetch informations from '%s'"
                                " (libavformat failure)",
@@ -120,7 +120,11 @@ void probe_ffmpeg(info_t *ipipe)
 
     translate_info(lavf_dmx_context, ipipe->probe_info);
 
+#if LIBAVFORMAT_VERSION_INT > AV_VERSION_INT(53,25,0)
+    avformat_close_input(&lavf_dmx_context);
+#else
     av_close_input_file(lavf_dmx_context);
+#endif
     return;
 }
 
