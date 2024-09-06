$NetBSD: patch-source_blender_blenkernel_intern_gpencil__geom__legacy.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/blenkernel/intern/gpencil_geom_legacy.cc.orig	2024-06-05 11:47:56.000000000 +0000
+++ source/blender/blenkernel/intern/gpencil_geom_legacy.cc
@@ -591,7 +591,7 @@ bool BKE_gpencil_stroke_stretch(bGPDstro
   const bool do_end = ELEM(mode, BOTH, END);
   float used_percent_length = overshoot_fac;
   CLAMP(used_percent_length, 1e-4f, 1.0f);
-  if (!isfinite(used_percent_length)) {
+  if (!std::isfinite(used_percent_length)) {
     /* #used_percent_length must always be finite, otherwise a segfault occurs.
      * Since this function should never segfault, set #used_percent_length to a safe fallback. */
     /* NOTE: This fallback is used if `gps->totpoints == 2`, see `MOD_gpencil_legacy_length.cc`. */
