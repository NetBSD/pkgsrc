$NetBSD: patch-src_hugin1_hugin_PreviewPanel.cpp,v 1.2 2026/03/08 20:08:05 adam Exp $

error: no matching function for call to 'max(double, float)'

--- src/hugin1/hugin/PreviewPanel.cpp.orig	2026-01-04 10:11:42.853636201 +0000
+++ src/hugin1/hugin/PreviewPanel.cpp
@@ -320,7 +320,7 @@ void PreviewPanel::updatePreview()
                 // find min and max
                 vigra::FindAverageAndVariance<float> mean;   // init functor
                 vigra::inspectImageIf(vigra::srcImageRange(panoImg, vigra::RGBToGrayAccessor<vigra::RGBValue<float>>()), vigra::srcImage(alpha), mean);
-                double min = std::max(mean.average()-3*sqrt(mean.variance()), 1e-6f);
+                double min = std::max(mean.average()-3.0*sqrt(mean.variance()), 1e-6);
                 double max = mean.average() + 3 * sqrt(mean.variance());
 
                 int mapping = wxConfigBase::Get()->Read("/ImageCache/Mapping", HUGIN_IMGCACHE_MAPPING_FLOAT);
