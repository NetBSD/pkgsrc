$NetBSD: patch-tools_mesh__sampling.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- tools/mesh_sampling.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ tools/mesh_sampling.cpp
@@ -36,6 +36,7 @@
  */
 
 #include <pcl/visualization/pcl_visualizer.h>
+#include <pcl/visualization/vtk/pcl_vtk_compatibility.h>
 #include <pcl/io/pcd_io.h>
 #include <pcl/io/vtk_lib_io.h>
 #include <pcl/common/transforms.h>
@@ -87,7 +88,8 @@ randPSurface (vtkPolyData * polydata, st
 
   double A[3], B[3], C[3];
   vtkIdType npts = 0;
-  vtkIdType *ptIds = nullptr;
+  vtkCellPtsPtr ptIds = nullptr;
+
   polydata->GetCellPoints (el, npts, ptIds);
   polydata->GetPoint (ptIds[0], A);
   polydata->GetPoint (ptIds[1], B);
@@ -138,7 +140,8 @@ uniform_sampling (vtkSmartPointer<vtkPol
 
   double p1[3], p2[3], p3[3], totalArea = 0;
   std::vector<double> cumulativeAreas (cells->GetNumberOfCells (), 0);
-  vtkIdType npts = 0, *ptIds = nullptr;
+  vtkIdType npts = 0;
+  vtkCellPtsPtr ptIds = nullptr;
   std::size_t cellId = 0;
   for (cells->InitTraversal (); cells->GetNextCell (npts, ptIds); cellId++)
   {
