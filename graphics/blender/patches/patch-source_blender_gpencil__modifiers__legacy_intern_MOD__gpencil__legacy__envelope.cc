$NetBSD: patch-source_blender_gpencil__modifiers__legacy_intern_MOD__gpencil__legacy__envelope.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/gpencil_modifiers_legacy/intern/MOD_gpencil_legacy_envelope.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/gpencil_modifiers_legacy/intern/MOD_gpencil_legacy_envelope.cc
@@ -99,7 +99,7 @@ static float calc_min_radius_v3v3(float 
   /* v is the determined minimal radius. In case p1 and p2 are the same, there is a
    * simple proof for the following formula using the geometric mean theorem and Thales theorem. */
   float v = len_squared_v3(p) / (2 * interpf(p1_dir, p2_dir, u));
-  if (v < 0 || !isfinite(v)) {
+  if (v < 0 || !std::isfinite(v)) {
     /* No limit to the radius from this segment. */
     return 1e16f;
   }
