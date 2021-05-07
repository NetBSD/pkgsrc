$NetBSD: patch-tools_pcd__viewer.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- tools/pcd_viewer.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ tools/pcd_viewer.cpp
@@ -45,7 +45,6 @@
 #include <pcl/io/pcd_io.h>
 #include <cfloat>
 #include <pcl/visualization/eigen.h>
-//#include <pcl/visualization/vtk.h>
 #include <pcl/visualization/point_cloud_handlers.h>
 #include <pcl/visualization/pcl_visualizer.h>
 #include <pcl/visualization/image_viewer.h>
