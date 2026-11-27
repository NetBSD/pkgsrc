$NetBSD: patch-source_blender_geometry_intern_extend__curves.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/geometry/intern/extend_curves.cc.orig	2025-03-10 17:27:09.000000000 +0000
+++ source/blender/geometry/intern/extend_curves.cc
@@ -331,7 +331,7 @@ bke::CurvesGeometry extend_curves(bke::CurvesGeometry 
 
       /* #used_percent_length must always be finite and non-zero. */
       const float used_percent_length = math::clamp(
-          isfinite(overshoot_fac) ? overshoot_fac : 0.1f, 1e-4f, 1.0f);
+          std::isfinite(overshoot_fac) ? overshoot_fac : 0.1f, 1e-4f, 1.0f);
 
       if (!follow_curvature || new_size == 2) {
         extend_curve_straight(used_percent_length,
