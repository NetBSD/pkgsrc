$NetBSD: patch-source_blender_geometry_intern_extend__curves.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/geometry/intern/extend_curves.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/geometry/intern/extend_curves.cc
@@ -322,7 +322,7 @@ bke::CurvesGeometry extend_curves(bke::C
 
       /* #used_percent_length must always be finite and non-zero. */
       const float used_percent_length = math::clamp(
-          isfinite(overshoot_fac) ? overshoot_fac : 0.1f, 1e-4f, 1.0f);
+          std::isfinite(overshoot_fac) ? overshoot_fac : 0.1f, 1e-4f, 1.0f);
 
       if (!follow_curvature) {
         extend_curves_straight(used_percent_length,
