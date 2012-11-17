$NetBSD: patch-import_import_ffmpeg.c,v 1.1 2012/11/17 21:46:44 markd Exp $

Fix build with ffmpeg 0.11. gentoo patch from Brennan Shacklett

--- import/import_ffmpeg.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ import/import_ffmpeg.c
@@ -314,7 +314,7 @@ do_avi:
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
     lavc_dec_context->error_resilience  = 2;
 #else
-    lavc_dec_context->error_recognition = 2;
+    lavc_dec_context->err_recognition = 2;
 #endif
     lavc_dec_context->error_concealment = 3;
     lavc_dec_context->workaround_bugs = FF_BUG_AUTODETECT;
