$NetBSD: patch-src_ffts_trig.c,v 1.1 2017/07/04 19:51:42 gson Exp $

Fix build error.  Submitted upstream in https://github.com/anthonix/ffts/pull/60.

--- src/ffts_trig.c
+++ src/ffts_trig.c
@@ -881,7 +881,7 @@ int
 ffts_generate_cosine_sine_pow2_32f(ffts_cpx_32f *const table, int table_size)
 {
     const ffts_cpx_64f *FFTS_RESTRICT ct;
-    const double_t *FFTS_RESTRICT hs;
+    const ffts_double_t *FFTS_RESTRICT hs;
     ffts_cpx_64f FFTS_ALIGN(16) w[32];
     int i, log_2, offset;
 
@@ -1136,4 +1136,4 @@ last:
     }
 
     return 0;
-}
\ No newline at end of file
+}
