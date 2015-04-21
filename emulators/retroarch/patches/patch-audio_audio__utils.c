$NetBSD: patch-audio_audio__utils.c,v 1.1 2015/04/21 17:18:01 joerg Exp $

--- audio/audio_utils.c.orig	2015-04-17 14:35:27.000000000 +0000
+++ audio/audio_utils.c
@@ -216,7 +216,7 @@ void audio_convert_float_to_s16_altivec(
    }
    audio_convert_float_to_s16_C(out, in, samples_in);
 }
-#elif defined(__ARM_NEON__)
+#elif defined(HAVE_NEON)
 /* Avoid potential hard-float/soft-float ABI issues. */
 void audio_convert_s16_float_asm(float *out, const int16_t *in,
       size_t samples, const float *gain);
@@ -402,7 +402,7 @@ void audio_convert_float_to_s16_ALLEGREX
  **/
 void audio_convert_init_simd(void)
 {
-#if defined(__ARM_NEON__) 
+#if defined(HAVE_NEON) 
    unsigned cpu = rarch_get_cpu_features();
    audio_convert_s16_to_float_arm = cpu & RETRO_SIMD_NEON ?
       audio_convert_s16_to_float_neon : audio_convert_s16_to_float_C;
