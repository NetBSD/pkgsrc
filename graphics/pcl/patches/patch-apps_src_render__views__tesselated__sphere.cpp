$NetBSD: patch-apps_src_render__views__tesselated__sphere.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/src/render_views_tesselated_sphere.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/src/render_views_tesselated_sphere.cpp
@@ -7,6 +7,7 @@
 
 #include <pcl/apps/render_views_tesselated_sphere.h>
 #include <pcl/point_types.h>
+#include <pcl/visualization/vtk/pcl_vtk_compatibility.h>
 
 #include <vtkActor.h>
 #include <vtkCamera.h>
@@ -26,6 +27,7 @@
 #include <vtkTransformFilter.h>
 #include <vtkTriangle.h>
 #include <vtkWorldPointPicker.h>
+#include <vtkIdTypeArray.h>
 
 #include <array>
 
@@ -34,7 +36,8 @@ pcl::apps::RenderViewsTesselatedSphere::
 {
   // center object
   double CoM[3];
-  vtkIdType npts_com = 0, *ptIds_com = nullptr;
+  vtkIdType npts_com = 0;
+  vtkCellPtsPtr ptIds_com = nullptr;
   vtkSmartPointer<vtkCellArray> cells_com = polydata_->GetPolys();
 
   double center[3], p1_com[3], p2_com[3], p3_com[3], totalArea_com = 0;
@@ -95,7 +98,8 @@ pcl::apps::RenderViewsTesselatedSphere::
   // * Compute area of the mesh
   //////////////////////////////
   vtkSmartPointer<vtkCellArray> cells = mapper->GetInput()->GetPolys();
-  vtkIdType npts = 0, *ptIds = nullptr;
+  vtkIdType npts = 0;
+  vtkCellPtsPtr ptIds = nullptr;
 
   double p1[3], p2[3], p3[3], totalArea = 0;
   for (cells->InitTraversal(); cells->GetNextCell(npts, ptIds);) {
@@ -363,7 +367,8 @@ pcl::apps::RenderViewsTesselatedSphere::
       polydata->BuildCells();
 
       vtkSmartPointer<vtkCellArray> cells = polydata->GetPolys();
-      vtkIdType npts = 0, *ptIds = nullptr;
+      vtkIdType npts = 0;
+      vtkCellPtsPtr ptIds = nullptr;
 
       double p1[3], p2[3], p3[3], area, totalArea = 0;
       for (cells->InitTraversal(); cells->GetNextCell(npts, ptIds);) {
