$NetBSD: patch-audio_audio__utils.h,v 1.1 2015/04/21 17:18:01 joerg Exp $

--- audio/audio_utils.h.orig	2015-04-17 14:35:56.000000000 +0000
+++ audio/audio_utils.h
@@ -93,7 +93,7 @@ void audio_convert_s16_to_float_altivec(
 void audio_convert_float_to_s16_altivec(int16_t *out,
       const float *in, size_t samples);
 
-#elif defined(__ARM_NEON__)
+#elif defined(HAVE_NEON)
 #define audio_convert_s16_to_float audio_convert_s16_to_float_arm
 #define audio_convert_float_to_s16 audio_convert_float_to_s16_arm
 
