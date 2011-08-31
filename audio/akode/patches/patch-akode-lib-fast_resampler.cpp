$NetBSD: patch-akode-lib-fast_resampler.cpp,v 1.1 2011/08/31 14:43:43 joerg Exp $

--- akode/lib/fast_resampler.cpp.orig	2011-08-30 13:31:41.000000000 +0000
+++ akode/lib/fast_resampler.cpp
@@ -37,7 +37,7 @@ FastResampler::FastResampler() : speed(1
 // A fast resampling by linear interpolation
 // I assume you know binary arithmetics and convertions if you're reading this
 // T is the input/output type, Arithm defines the used arithmetic
-template<typename T, typename S, template<typename S> class Arithm>
+template<typename T, typename S, template<typename U> class Arithm>
 static bool _doBuffer(AudioFrame* in, AudioFrame* out, float speed, unsigned sample_rate)
 {
     unsigned long vt_pos_start = 0;  // virtual positions of new sample
