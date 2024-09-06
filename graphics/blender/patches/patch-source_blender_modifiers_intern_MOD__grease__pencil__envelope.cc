$NetBSD: patch-source_blender_modifiers_intern_MOD__grease__pencil__envelope.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/modifiers/intern/MOD_grease_pencil_envelope.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/modifiers/intern/MOD_grease_pencil_envelope.cc
@@ -139,7 +139,7 @@ static float calc_min_radius_v3v3(const 
    * simple proof for the following formula using the geometric mean theorem and Thales theorem. */
   const float v = math::length_squared(math::interpolate(p2, p1, u)) /
                   (2 * math::interpolate(p2_dir, p1_dir, u));
-  if (v < 0 || !isfinite(v)) {
+  if (v < 0 || !std::isfinite(v)) {
     /* No limit to the radius from this segment. */
     return unlimited_radius;
   }
