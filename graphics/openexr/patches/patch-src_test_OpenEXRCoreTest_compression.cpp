$NetBSD: patch-src_test_OpenEXRCoreTest_compression.cpp,v 1.1 2023/06/16 21:17:06 wiz Exp $

error: 'isnan' was not declared in this scope; did you mean 'std::isnan'
https://github.com/AcademySoftwareFoundation/openexr/commit/729f42648d5a522bba0d8f52061c0368a5d31bbb

--- src/test/OpenEXRCoreTest/compression.cpp.orig	2023-06-01 04:56:14.000000000 +0000
+++ src/test/OpenEXRCoreTest/compression.cpp
@@ -159,7 +159,7 @@ inline bool
 withinDWAErrorBounds (const uint16_t a, const uint16_t b)
 {
     float a1 = imath_half_to_float (a);
-    if (!isnan (a1))
+    if (!std::isnan (a1))
     {
         float a2 = imath_half_to_float (b);
         float denominator =
