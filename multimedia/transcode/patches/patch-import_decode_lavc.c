$NetBSD: patch-import_decode_lavc.c,v 1.2 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- import/decode_lavc.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ import/decode_lavc.c
@@ -170,7 +170,7 @@ void decode_lavc(decode_t *decode)
 
   // Set these to the expected values so that ffmpeg's decoder can
   // properly detect interlaced input.
-  lavc_dec_context = avcodec_alloc_context();
+  lavc_dec_context = avcodec_alloc_context3(NULL);
   if (lavc_dec_context == NULL) {
       tc_log_error(__FILE__, "Could not allocate enough memory.");
       goto decoder_error;
@@ -181,12 +181,12 @@ void decode_lavc(decode_t *decode)
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
   lavc_dec_context->error_resilience  = 2;
 #else
-  lavc_dec_context->error_recognition = 2;
+  lavc_dec_context->err_recognition = 2;
 #endif
   lavc_dec_context->error_concealment = 3;
   lavc_dec_context->workaround_bugs = FF_BUG_AUTODETECT;
 
-  if (avcodec_open(lavc_dec_context, lavc_dec_codec) < 0) {
+  if (avcodec_open2(lavc_dec_context, lavc_dec_codec, NULL) < 0) {
       tc_log_error(__FILE__, "Could not initialize the '%s' codec.",
 		   codec->name);
       goto decoder_error;
