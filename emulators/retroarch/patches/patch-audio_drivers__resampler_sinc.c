$NetBSD: patch-audio_drivers__resampler_sinc.c,v 1.1 2015/04/21 17:18:01 joerg Exp $

--- audio/drivers_resampler/sinc.c.orig	2015-02-03 06:43:44.000000000 +0000
+++ audio/drivers_resampler/sinc.c
@@ -399,7 +399,7 @@ static void process_sinc(rarch_sinc_resa
    /* movehl { X, R, X, L } == { X, R, X, R } */
    _mm_store_ss(out_buffer + 1, _mm_movehl_ps(sum, sum));
 }
-#elif defined(__ARM_NEON__)
+#elif defined(HAVE_NEON)
 
 #if SINC_COEFF_LERP
 #error "NEON asm does not support SINC lerp."
@@ -504,7 +504,7 @@ static void *resampler_sinc_new(const st
    }
 
    /* Be SIMD-friendly. */
-#if (defined(__AVX__) && ENABLE_AVX) || defined(__ARM_NEON__)
+#if (defined(__AVX__) && ENABLE_AVX) || defined(HAVE_NEON)
    re->taps = (re->taps + 7) & ~7;
 #else
    re->taps = (re->taps + 3) & ~3;
@@ -532,7 +532,7 @@ static void *resampler_sinc_new(const st
    RARCH_LOG("Sinc resampler [AVX]\n");
 #elif defined(__SSE__)
    RARCH_LOG("Sinc resampler [SSE]\n");
-#elif defined(__ARM_NEON__)
+#elif defined(HAVE_NEON)
    process_sinc_func = mask & RESAMPLER_SIMD_NEON 
       ? process_sinc_neon : process_sinc_C;
    RARCH_LOG("Sinc resampler [%s]\n",
