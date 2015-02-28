$NetBSD: patch-src_pulsecore_mix__neon.c,v 1.1 2015/02/28 23:41:58 joerg Exp $

--- src/pulsecore/mix_neon.c.orig	2015-02-25 15:03:12.000000000 +0000
+++ src/pulsecore/mix_neon.c
@@ -175,6 +175,10 @@ static void pa_mix2_ch4_s16ne_neon(pa_mi
 
     int32x4_t sv0, sv1;
 
+#ifdef __clang__
+    sv0 = vld1q_s32(streams[0].linear);
+    sv1 = vld1q_s32(streams[1].linear);
+#else
     __asm__ __volatile__ (
         "vld1.s32 %h[sv0], [%[lin0]]         \n\t"
         "vld1.s32 %h[sv1], [%[lin1]]         \n\t"
@@ -182,6 +186,7 @@ static void pa_mix2_ch4_s16ne_neon(pa_mi
         : [lin0] "r" (streams[0].linear), [lin1] "r" (streams[1].linear)
         : /* clobber list */
     );
+#endif
 
     length /= sizeof(int16_t);
     for (; length >= 4; length -= 4) {
