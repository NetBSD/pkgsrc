$NetBSD: patch-source_blender_geometry_intern_uv__parametrizer.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/geometry/intern/uv_parametrizer.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/geometry/intern/uv_parametrizer.cc
@@ -652,7 +652,7 @@ static PVert *p_vert_add(ParamHandle *ha
    * Note that values within the calculation may _become_ non-finite,
    * so the rest of the code still needs to take this possibility into account. */
   for (int i = 0; i < 3; i++) {
-    if (UNLIKELY(!isfinite(v->co[i]))) {
+    if (UNLIKELY(!std::isfinite(v->co[i]))) {
       v->co[i] = 0.0f;
     }
   }
