$NetBSD: patch-source_blender_blenkernel_intern_mesh__validate.cc,v 1.5 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/blenkernel/intern/mesh_validate.cc.orig	2024-06-05 11:47:56.000000000 +0000
+++ source/blender/blenkernel/intern/mesh_validate.cc
@@ -256,7 +256,7 @@ bool BKE_mesh_validate_arrays(Mesh *mesh
 
   for (i = 0; i < verts_num; i++) {
     for (j = 0; j < 3; j++) {
-      if (!isfinite(vert_positions[i][j])) {
+      if (!std::isfinite(vert_positions[i][j])) {
         PRINT_ERR("\tVertex %u: has invalid coordinate", i);
 
         if (do_fixes) {
@@ -748,7 +748,7 @@ bool BKE_mesh_validate_arrays(Mesh *mesh
 
       for (j = 0, dw = dv->dw; j < dv->totweight; j++, dw++) {
         /* NOTE: greater than max defgroups is accounted for in our code, but not < 0. */
-        if (!isfinite(dw->weight)) {
+        if (!std::isfinite(dw->weight)) {
           PRINT_ERR("\tVertex deform %u, group %u has weight: %f", i, dw->def_nr, dw->weight);
           if (do_fixes) {
             dw->weight = 0.0f;
