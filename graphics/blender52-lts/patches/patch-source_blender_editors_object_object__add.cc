$NetBSD: patch-source_blender_editors_object_object__add.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/editors/object/object_add.cc.orig	2026-09-13 11:34:09.094217335 +0000
+++ source/blender/editors/object/object_add.cc
@@ -870,7 +870,7 @@ static wmOperatorStatus lattice_add_to_selected_exec(b
 
     /* Prevent invalid or zero lattice size, fallback to 1.0f. */
     for (int i = 0; i < 3; i++) {
-      if (!isfinite(ob_lattice->scale[i]) || ob_lattice->scale[i] <= FLT_EPSILON) {
+      if (!std::isfinite(ob_lattice->scale[i]) || ob_lattice->scale[i] <= FLT_EPSILON) {
         ob_lattice->scale[i] = 1.0f;
       }
     }
