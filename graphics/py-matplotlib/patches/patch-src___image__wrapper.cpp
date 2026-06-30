$NetBSD: patch-src___image__wrapper.cpp,v 1.1 2026/06/30 10:18:27 ryoon Exp $

* Fix fingerprint mismatch for std::clamp().
  abs() returns int, not double.

--- src/_image_wrapper.cpp.orig	2026-06-30 09:58:33.168256719 +0000
+++ src/_image_wrapper.cpp
@@ -266,7 +266,7 @@ calculate_rms_and_diff(py::array_t<unsigned char> expe
 
                 if (k != 3) { // Hard-code a fully solid alpha channel by omitting it.
                     diff(i, j, k) = static_cast<unsigned char>(std::clamp(
-                        abs(pixel_diff) * 10, // Expand differences in luminance domain.
+                        std::abs(pixel_diff) * 10, // Expand differences in luminance domain.
                         0.0, 255.0));
                 }
             }
