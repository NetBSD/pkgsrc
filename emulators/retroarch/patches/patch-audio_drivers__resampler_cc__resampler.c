$NetBSD: patch-audio_drivers__resampler_cc__resampler.c,v 1.1 2015/04/21 17:18:01 joerg Exp $

--- audio/drivers_resampler/cc_resampler.c.orig	2015-04-17 14:34:27.000000000 +0000
+++ audio/drivers_resampler/cc_resampler.c
@@ -388,7 +388,7 @@ static void resampler_CC_upsample(void *
 }
 
 
-#elif defined (__ARM_NEON__)
+#elif defined (HAVE_NEON)
 
 #define CC_RESAMPLER_IDENT "NEON"
 
