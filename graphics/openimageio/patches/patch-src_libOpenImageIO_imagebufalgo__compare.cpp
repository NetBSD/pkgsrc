$NetBSD: patch-src_libOpenImageIO_imagebufalgo__compare.cpp,v 1.3 2025/08/14 07:43:27 wiz Exp $

https://github.com/AcademySoftwareFoundation/OpenImageIO/pull/4857

--- src/libOpenImageIO/imagebufalgo_compare.cpp.orig	2025-08-14 07:19:04.842166717 +0000
+++ src/libOpenImageIO/imagebufalgo_compare.cpp
@@ -80,11 +80,11 @@ ImageBufAlgo::PixelStats::operator=(Pixe
 inline void
 val(ImageBufAlgo::PixelStats& p, int c, float value)
 {
-    if (isnan(value)) {
+    if (std::isnan(value)) {
         ++p.nancount[c];
         return;
     }
-    if (isinf(value)) {
+    if (std::isinf(value)) {
         ++p.infcount[c];
         return;
     }
@@ -217,10 +217,10 @@ compare_value(ImageBuf::ConstIterator<BU
               bool& warned, float failthresh, float warnthresh,
               float failrelative, float warnrelative)
 {
-    if (!isfinite(aval) || !isfinite(bval)) {
-        if (isnan(aval) == isnan(bval) && isinf(aval) == isinf(bval))
+    if (!std::isfinite(aval) || !std::isfinite(bval)) {
+        if (std::isnan(aval) == std::isnan(bval) && std::isinf(aval) == std::isinf(bval))
             return;  // NaN may match NaN, Inf may match Inf
-        if (isfinite(result.maxerror)) {
+        if (std::isfinite(result.maxerror)) {
             // non-finite errors trump finite ones
             result.maxerror = std::numeric_limits<float>::infinity();
             result.maxx     = a.x();
