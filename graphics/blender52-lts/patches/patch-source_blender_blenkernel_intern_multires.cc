$NetBSD: patch-source_blender_blenkernel_intern_multires.cc,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- source/blender/blenkernel/intern/multires.cc.orig	2026-09-13 16:31:11.835596219 +0000
+++ source/blender/blenkernel/intern/multires.cc
@@ -569,7 +569,7 @@ void old_mdisps_bilinear(float out[3], float (*disps)[
   const int st_max = st - 1;
   float d[4][3], d2[2][3];
 
-  if (!disps || isnan(u) || isnan(v)) {
+  if (!disps || std::isnan(u) || std::isnan(v)) {
     return;
   }
 
