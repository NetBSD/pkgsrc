$NetBSD: patch-import_probe_ffmpeg.c,v 1.1 2012/11/17 21:46:44 markd Exp $

Fix build with ffmpeg 0.11. gentoo patch from Brennan Shacklett

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
