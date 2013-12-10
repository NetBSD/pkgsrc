$NetBSD: patch-lib-src_soundtouch_source_SoundTouch_FIRFilter.cpp,v 1.1 2013/12/10 14:23:44 jperkin Exp $

Fix pow() argument types.

--- lib-src/soundtouch/source/SoundTouch/FIRFilter.cpp.orig	2006-11-15 04:12:11.000000000 +0000
+++ lib-src/soundtouch/source/SoundTouch/FIRFilter.cpp
@@ -177,7 +177,7 @@ void FIRFilter::setCoefficients(const SA
     assert(length == newLength);
 
     resultDivFactor = uResultDivFactor;
-    resultDivider = (SAMPLETYPE)pow(2, resultDivFactor);
+    resultDivider = (SAMPLETYPE)pow(2, (double)resultDivFactor);
 
     delete[] filterCoeffs;
     filterCoeffs = new SAMPLETYPE[length];
