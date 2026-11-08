$NetBSD: patch-source_blender_blenkernel_intern_fluid.cc,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- source/blender/blenkernel/intern/fluid.cc.orig	2026-09-13 16:15:59.547366245 +0000
+++ source/blender/blenkernel/intern/fluid.cc
@@ -434,8 +434,8 @@ static void manta_set_domain_from_mesh(FluidDomainSett
   /* Apply object scale. */
   for (i = 0; i < 3; i++) {
     const float scale = ob->scale[i];
-    size[i] = fabsf(size[i] * (isfinite(scale) ? scale : 1.0f));
-    if (!isfinite(size[i])) {
+    size[i] = fabsf(size[i] * (std::isfinite(scale) ? scale : 1.0f));
+    if (!std::isfinite(size[i])) {
       size[i] = 1.0f;
     }
   }
