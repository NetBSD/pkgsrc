$NetBSD: patch-visualization_include_pcl_visualization_common_actor__map.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/common/actor_map.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/include/pcl/visualization/common/actor_map.h
@@ -43,6 +43,7 @@
 
 #include <vtkLODActor.h>
 #include <vtkSmartPointer.h>
+#include <vtkIdTypeArray.h>
 
 #include <map>
 #include <unordered_map>
