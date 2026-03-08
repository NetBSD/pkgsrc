$NetBSD: patch-src_hugin__base_huginapp_ImageCache.cpp,v 1.2 2026/03/08 20:08:05 adam Exp $

error: no matching function for call to 'max(double, float)'

--- src/hugin_base/huginapp/ImageCache.cpp.orig	2026-01-04 10:05:46.860282953 +0000
+++ src/hugin_base/huginapp/ImageCache.cpp
@@ -59,7 +59,7 @@ void convertTo8Bit(SrcIMG& src, const st
         vigra::RGBToGrayAccessor<vigra::RGBValue<float> > ga;
         vigra::FindAverageAndVariance<float> mean;   // init functor
         vigra::inspectImage(srcImageRange(src, ga), mean);
-        min = std::max(mean.average() - 3 * sqrt(mean.variance()), 1e-6f);
+        min = std::max(mean.average() - 3.0 * sqrt(mean.variance()), 1e-6);
         max = mean.average() + 3 * sqrt(mean.variance());
         mapping = desiredMapping != -1 ? desiredMapping : HUGIN_IMGCACHE_MAPPING_FLOAT;
     }
