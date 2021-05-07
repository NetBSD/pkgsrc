$NetBSD: patch-visualization_src_interactor__style.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/src/interactor_style.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/src/interactor_style.cpp
@@ -36,6 +36,7 @@
  *
  */
 
+#include <fstream>
 #include <list>
 #include <pcl/common/angles.h>
 #include <pcl/visualization/common/io.h>
@@ -137,7 +138,7 @@ pcl::visualization::PCLVisualizerInterac
 {
   FindPokedRenderer (Interactor->GetEventPosition ()[0], Interactor->GetEventPosition ()[1]);
 
-  ofstream ofs_cam (file.c_str ());
+  std::ofstream ofs_cam (file.c_str ());
   if (!ofs_cam.is_open ())
   {
     return (false);
