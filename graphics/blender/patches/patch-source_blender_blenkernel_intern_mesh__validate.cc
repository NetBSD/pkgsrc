$NetBSD: patch-source_blender_blenkernel_intern_mesh__validate.cc,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- source/blender/blenkernel/intern/mesh_validate.cc.orig	2022-11-04 00:33:06.000000000 +0000
+++ source/blender/blenkernel/intern/mesh_validate.cc
@@ -307,7 +307,7 @@ bool BKE_mesh_validate_arrays(Mesh *mesh
     bool fix_normal = true;
 
     for (j = 0; j < 3; j++) {
-      if (!isfinite(mv->co[j])) {
+      if (!std::isfinite(mv->co[j])) {
         PRINT_ERR("\tVertex %u: has invalid coordinate", i);
 
         if (do_fixes) {
@@ -814,7 +814,7 @@ bool BKE_mesh_validate_arrays(Mesh *mesh
 
       for (j = 0, dw = dv->dw; j < dv->totweight; j++, dw++) {
         /* NOTE: greater than max defgroups is accounted for in our code, but not < 0. */
-        if (!isfinite(dw->weight)) {
+        if (!std::isfinite(dw->weight)) {
           PRINT_ERR("\tVertex deform %u, group %u has weight: %f", i, dw->def_nr, dw->weight);
           if (do_fixes) {
             dw->weight = 0.0f;
