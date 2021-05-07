$NetBSD: patch-apps_modeler_src_cloud__mesh.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/modeler/src/cloud_mesh.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/modeler/src/cloud_mesh.cpp
@@ -198,7 +198,7 @@ pcl::modeler::CloudMesh::updateVtkPolygo
   if (cloud_->is_dense) {
     for (const auto& polygon : polygons_) {
       vtk_polygons_->InsertNextCell(polygon.vertices.size());
-      for (const unsigned int& vertex : polygon.vertices)
+      for (const auto& vertex : polygon.vertices)
         vtk_polygons_->InsertCellPoint(vertex);
     }
   }
@@ -208,7 +208,7 @@ pcl::modeler::CloudMesh::updateVtkPolygo
 
     for (const auto& polygon : polygons_) {
       vtk_polygons_->InsertNextCell(polygon.vertices.size());
-      for (const unsigned int& vertex : polygon.vertices)
+      for (const auto& vertex : polygon.vertices)
         vtk_polygons_->InsertCellPoint((*indices)[vertex]);
     }
   }
