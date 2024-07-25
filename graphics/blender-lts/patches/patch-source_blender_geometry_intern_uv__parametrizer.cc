$NetBSD: patch-source_blender_geometry_intern_uv__parametrizer.cc,v 1.1 2024/07/25 06:00:39 ryoon Exp $

--- source/blender/geometry/intern/uv_parametrizer.cc.orig	2024-07-02 09:38:38.338288091 +0000
+++ source/blender/geometry/intern/uv_parametrizer.cc
@@ -681,7 +681,7 @@ static PVert *p_vert_add(ParamHandle *ha
    * Note that values within the calculation may _become_ non-finite,
    * so the rest of the code still needs to take this possibility into account. */
   for (int i = 0; i < 3; i++) {
-    if (UNLIKELY(!isfinite(v->co[i]))) {
+    if (UNLIKELY(!std::isfinite(v->co[i]))) {
       v->co[i] = 0.0f;
     }
   }
