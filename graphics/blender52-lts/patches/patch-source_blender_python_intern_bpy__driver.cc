$NetBSD: patch-source_blender_python_intern_bpy__driver.cc,v 1.1 2026/11/08 16:15:20 ryoon Exp $

--- source/blender/python/intern/bpy_driver.cc.orig	2026-09-13 21:31:36.728343565 +0000
+++ source/blender/python/intern/bpy_driver.cc
@@ -570,7 +570,7 @@ float BPY_driver_exec(PathResolvedRNA *anim_rna,
     PyGILState_Release(gilstate);
   }
 
-  if (UNLIKELY(!isfinite(result))) {
+  if (UNLIKELY(!std::isfinite(result))) {
     fprintf(stderr, "\t%s: driver '%s' evaluates to '%f'\n", __func__, driver->expression, result);
     return 0.0f;
   }
