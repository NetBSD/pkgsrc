$NetBSD: patch-src_hugin1_base__wx_wxImageCache.cpp,v 1.2 2026/03/08 20:08:05 adam Exp $

error: no matching function for call to 'max(double, float)'

--- src/hugin1/base_wx/wxImageCache.cpp.orig	2026-01-04 10:09:55.589779097 +0000
+++ src/hugin1/base_wx/wxImageCache.cpp
@@ -41,7 +41,7 @@ wxImage imageCacheEntry2wxImage(ImageCac
         // create temporary image with remapped tone scale
         vigra::BRGBImage mappedImg(e->imageFloat->size());
         // scale image to (mean - 3 * std deviation) - (mean + 3 * std deviation), 
-        vigra_ext::applyMapping(srcImageRange(*(e->imageFloat)), destImage(mappedImg), std::max(mean.average() - 3 * sqrt(mean.variance()), 1e-6f), mean.average() + 3 * sqrt(mean.variance()), mapping);
+        vigra_ext::applyMapping(srcImageRange(*(e->imageFloat)), destImage(mappedImg), std::max(mean.average() - 3.0 * sqrt(mean.variance()), 1e-6), mean.average() + 3.0 * sqrt(mean.variance()), mapping);
         // convert to wxImage
         wxImage mappedwxImg(mappedImg.width(), mappedImg.height(), (unsigned char *)mappedImg.data(), true);
         return mappedwxImg.Copy();
