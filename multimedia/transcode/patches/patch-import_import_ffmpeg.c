$NetBSD: patch-import_import_ffmpeg.c,v 1.2 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- import/import_ffmpeg.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ import/import_ffmpeg.c
@@ -302,7 +302,7 @@ do_avi:
 
     // Set these to the expected values so that ffmpeg's decoder can
     // properly detect interlaced input.
-    lavc_dec_context = avcodec_alloc_context();
+    lavc_dec_context = avcodec_alloc_context3(lavc_dec_codec);
     if (lavc_dec_context == NULL) {
       tc_log_error(MOD_NAME, "Could not allocate enough memory.");
       return TC_IMPORT_ERROR;
@@ -314,7 +314,7 @@ do_avi:
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
     lavc_dec_context->error_resilience  = 2;
 #else
-    lavc_dec_context->error_recognition = 2;
+    lavc_dec_context->err_recognition = 2;
 #endif
     lavc_dec_context->error_concealment = 3;
     lavc_dec_context->workaround_bugs = FF_BUG_AUTODETECT;
@@ -344,7 +344,7 @@ do_avi:
     }
 
     TC_LOCK_LIBAVCODEC;
-    ret = avcodec_open(lavc_dec_context, lavc_dec_codec);
+    ret = avcodec_open2(lavc_dec_context, lavc_dec_codec, NULL);
     TC_UNLOCK_LIBAVCODEC;
     if (ret < 0) {
       tc_log_warn(MOD_NAME, "Could not initialize the '%s' codec.",
