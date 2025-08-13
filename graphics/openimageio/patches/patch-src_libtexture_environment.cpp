$NetBSD: patch-src_libtexture_environment.cpp,v 1.1 2025/08/13 06:35:14 wiz Exp $

--- src/libtexture/environment.cpp.orig	2025-08-13 06:20:32.653170686 +0000
+++ src/libtexture/environment.cpp
@@ -267,9 +267,9 @@ vector_to_latlong(const Imath::V3f& R, b
         t = 0.5f - atan2f(R.z, hypotf(R.x, R.y)) / (float)M_PI;
     }
     // learned from experience, beware NaNs
-    if (isnan(s))
+    if (std::isnan(s))
         s = 0.0f;
-    if (isnan(t))
+    if (std::isnan(t))
         t = 0.0f;
 }
 
