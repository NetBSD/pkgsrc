$NetBSD: patch-export_aud__aux.c,v 1.1 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- export/aud_aux.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ export/aud_aux.c
@@ -346,7 +346,7 @@ static int tc_audio_init_ffmpeg(vob_t *v
 
     //-- set parameters (bitrate, channels and sample-rate) --
     //--------------------------------------------------------
-    avcodec_get_context_defaults(&mpa_ctx);
+    avcodec_get_context_defaults3(&mpa_ctx, mpa_codec);
 #if LIBAVCODEC_VERSION_MAJOR < 53
     mpa_ctx.codec_type  = CODEC_TYPE_AUDIO;
 #else
@@ -359,7 +359,7 @@ static int tc_audio_init_ffmpeg(vob_t *v
     //-- open codec --
     //----------------
     TC_LOCK_LIBAVCODEC;
-    ret = avcodec_open(&mpa_ctx, mpa_codec);
+    ret = avcodec_open2(&mpa_ctx, mpa_codec, NULL);
     TC_UNLOCK_LIBAVCODEC;
     if (ret < 0) {
         tc_warn("tc_audio_init_ffmpeg: could not open %s codec !",
