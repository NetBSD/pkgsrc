$NetBSD: patch-src_effects_Compressor2.cpp,v 1.1 2026/07/22 15:24:33 ryoon Exp $

--- src/effects/Compressor2.cpp.orig	2026-03-08 15:09:15.602352465 +0000
+++ src/effects/Compressor2.cpp
@@ -1138,7 +1138,7 @@ double EffectCompressor2::CompressorGain(double env)
 
    // envDB can become NaN is env is exactly zero.
    // As solution, use a very low dB value to prevent NaN propagation.
-   if(isnan(envDB))
+   if(std::isnan(envDB))
       envDB = -200;
 
    kneeCond = 2.0 * (envDB - mThresholdDB);
