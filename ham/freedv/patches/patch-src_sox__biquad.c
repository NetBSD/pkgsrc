$NetBSD: patch-src_sox__biquad.c,v 1.1 2016/01/19 04:03:21 dbj Exp $

Avoid calling a sox internal function that is no longer
exported by the library.

--- src/sox_biquad.c.orig	2014-06-04 11:05:20.000000000 +0000
+++ src/sox_biquad.c
@@ -34,9 +34,6 @@
 
 #define N_MAX 1024
 
-int lsx_biquad_flow(sox_effect_t * effp, const sox_sample_t *ibuf,
-                    sox_sample_t *obuf, size_t *isamp, size_t *osamp);
-
 void sox_biquad_start(void)
 {
     int r = sox_init();
@@ -94,7 +91,7 @@ void sox_biquad_filter(void *sbq, short 
     for(i=0; i<n; i++)
         ibuf[i] = SOX_SIGNED_16BIT_TO_SAMPLE(in[i], clips);
     isamp = osamp = (unsigned int)n;
-    lsx_biquad_flow(e, ibuf, obuf, &isamp, &osamp);
+    e->handler.flow(e, ibuf, obuf, &isamp, &osamp);
     for(i=0; i<n; i++)
         out[i] = SOX_SAMPLE_TO_SIGNED_16BIT(obuf[i], clips); 
 }
