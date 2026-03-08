$NetBSD: patch-src_tools_linefind.cpp,v 1.2 2026/03/08 20:08:05 adam Exp $

error: no matching function for call to 'max(double, float)'

--- src/tools/linefind.cpp.orig	2026-01-04 10:08:44.474110831 +0000
+++ src/tools/linefind.cpp
@@ -87,7 +87,7 @@ void convertToUInt8(SrcIMG& src, const s
          */
         vigra::FindAverageAndVariance<float> mean;   // init functor
         vigra::inspectImage(srcImageRange(src, vigra::RGBToGrayAccessor<typename SrcIMG::PixelType>()), mean);
-        const double minVal = std::max(mean.average() - 3 * sqrt(mean.variance()), 1e-6f);
+        const double minVal = std::max(mean.average() - 3.0 * sqrt(mean.variance()), 1e-6);
         const double maxVal = mean.average() + 3 * sqrt(mean.variance());
         vigra_ext::applyMapping(srcImageRange(src), destImage(dest), minVal, maxVal, 1);
     }
@@ -111,7 +111,7 @@ void convertGrayToUInt8(SrcIMG& src, con
          */
         vigra::FindAverageAndVariance<float> mean;   // init functor
         vigra::inspectImage(srcImageRange(src), mean);
-        const double minVal = std::max(mean.average() - 3 * sqrt(mean.variance()), 1e-6f);
+        const double minVal = std::max(mean.average() - 3.0 * sqrt(mean.variance()), 1e-6);
         const double maxVal = mean.average() + 3 * sqrt(mean.variance());
         vigra_ext::applyMapping(srcImageRange(src), destImage(dest), minVal, maxVal, 1);
     }
