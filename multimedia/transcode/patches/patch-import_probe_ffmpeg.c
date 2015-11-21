$NetBSD: patch-import_probe_ffmpeg.c,v 1.2 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- import/probe_ffmpeg.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ import/probe_ffmpeg.c
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
@@ -120,7 +120,7 @@ void probe_ffmpeg(info_t *ipipe)
 
     translate_info(lavf_dmx_context, ipipe->probe_info);
 
-    av_close_input_file(lavf_dmx_context);
+    avformat_close_input(&lavf_dmx_context);
     return;
 }
 
