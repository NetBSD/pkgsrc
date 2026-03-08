$NetBSD: patch-src_hugin__cpfind_cpfind_PanoDetectorLogic.cpp,v 1.2 2026/03/08 20:08:05 adam Exp $

error: no matching function for call to 'max(double, float)'

--- src/hugin_cpfind/cpfind/PanoDetectorLogic.cpp.orig	2026-01-04 10:10:49.755602839 +0000
+++ src/hugin_cpfind/cpfind/PanoDetectorLogic.cpp
@@ -302,7 +302,7 @@ bool PanoDetector::AnalyzeImage(ImgData&
             {
                 vigra::FindAverageAndVariance<float> mean;   // init functor
                 vigra::inspectImage(vigra::srcImageRange(*image), mean);
-                minVal = std::max(mean.average() - 3 * sqrt(mean.variance()), 1e-6f);
+                minVal = std::max(mean.average() - 3.0 * sqrt(mean.variance()), 1e-6);
                 maxVal = mean.average() + 3 * sqrt(mean.variance());;
             }
             else
@@ -560,7 +560,7 @@ bool PanoDetector::AnalyzeImage(ImgData&
                             {
                                 vigra::FindAverageAndVariance<float> mean;   // init functor
                                 vigra::inspectImage(vigra::srcImageRange(*rgbImage, vigra::RGBToGrayAccessor<vigra::RGBValue<double> >()), mean);
-                                minVal = std::max(mean.average() - 3 * sqrt(mean.variance()), 1e-6f);
+                                minVal = std::max(mean.average() - 3.0 * sqrt(mean.variance()), 1e-6);
                                 maxVal = mean.average() + 3 * sqrt(mean.variance());;
                             }
                             else
