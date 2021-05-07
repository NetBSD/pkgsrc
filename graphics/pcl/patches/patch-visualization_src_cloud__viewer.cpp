$NetBSD: patch-visualization_src_cloud__viewer.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/src/cloud_viewer.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/src/cloud_viewer.cpp
@@ -40,6 +40,9 @@
 #include <pcl/visualization/boost.h>
 #include <pcl/memory.h>
 
+#include <vtkOrientationMarkerWidget.h>
+#include <vtkRenderWindowInteractor.h>
+
 #include <mutex>
 #include <thread>
 
