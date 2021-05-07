$NetBSD: patch-apps_3d__rec__framework_include_pcl_apps_3d__rec__framework_utils_vtk__model__sampling.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/3d_rec_framework/include/pcl/apps/3d_rec_framework/utils/vtk_model_sampling.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/3d_rec_framework/include/pcl/apps/3d_rec_framework/utils/vtk_model_sampling.h
@@ -9,6 +9,8 @@
 
 #include <pcl/common/common.h>
 
+#include <pcl/visualization/vtk/pcl_vtk_compatibility.h>
+
 #include <vtkCellArray.h>
 #include <vtkPLYReader.h>
 #include <vtkPolyData.h>
@@ -74,7 +76,7 @@ randPSurface(vtkPolyData* polydata,
 
   double A[3], B[3], C[3];
   vtkIdType npts = 0;
-  vtkIdType* ptIds = nullptr;
+  vtkCellPtsPtr ptIds = nullptr;
   polydata->GetCellPoints(el, npts, ptIds);
 
   if (ptIds == nullptr)
@@ -98,7 +100,9 @@ uniform_sampling(const vtkSmartPointer<v
   double p1[3], p2[3], p3[3], totalArea = 0;
   std::vector<double> cumulativeAreas(cells->GetNumberOfCells(), 0);
   std::size_t i = 0;
-  vtkIdType npts = 0, *ptIds = nullptr;
+  vtkIdType npts = 0;
+  vtkCellPtsPtr ptIds = nullptr;
+
   for (cells->InitTraversal(); cells->GetNextCell(npts, ptIds); i++) {
     polydata->GetPoint(ptIds[0], p1);
     polydata->GetPoint(ptIds[1], p2);
