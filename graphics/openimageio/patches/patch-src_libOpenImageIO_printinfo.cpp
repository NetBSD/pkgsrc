$NetBSD: patch-src_libOpenImageIO_printinfo.cpp,v 1.1 2025/08/13 06:35:14 wiz Exp $

--- src/libOpenImageIO/printinfo.cpp.orig	2025-08-13 06:20:47.321951087 +0000
+++ src/libOpenImageIO/printinfo.cpp
@@ -78,9 +78,9 @@ stats_num(float val, int maxval, bool ro
     // Ensure uniform printing of NaN and Inf on all platforms
     using Strutil::fmt::format;
     std::string result;
-    if (isnan(val))
+    if (std::isnan(val))
         result = "nan";
-    else if (isinf(val))
+    else if (std::isinf(val))
         result = "inf";
     else if (maxval == 0) {
         result = format("{:f}", val);
@@ -245,7 +245,7 @@ print_deep_stats(std::ostream& out, stri
                 for (unsigned int s = 0; s < samples; ++s) {
                     for (int c = 0; c < nchannels; ++c) {
                         float d = input.deep_value(x, y, z, c, s);
-                        if (!isfinite(d)) {
+                        if (!std::isfinite(d)) {
                             if (nonfinites++ == 0) {
                                 nonfinite_pixel.setValue(x, y, z);
                                 nonfinite_pixel_samp = s;
