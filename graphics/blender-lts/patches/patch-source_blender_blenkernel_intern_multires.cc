$NetBSD: patch-source_blender_blenkernel_intern_multires.cc,v 1.2 2026/11/27 13:46:27 adam Exp $

--- source/blender/blenkernel/intern/multires.cc.orig	2025-07-31 05:35:24.000000000 +0000
+++ source/blender/blenkernel/intern/multires.cc
@@ -1268,7 +1268,7 @@ void old_mdisps_bilinear(float out[3], float (*disps)[
   const int st_max = st - 1;
   float d[4][3], d2[2][3];
 
-  if (!disps || isnan(u) || isnan(v)) {
+  if (!disps || std::isnan(u) || std::isnan(v)) {
     return;
   }
 
