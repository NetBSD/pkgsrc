$NetBSD: patch-surface_src_vtk__smoothing_vtk__utils.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- surface/src/vtk_smoothing/vtk_utils.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ surface/src/vtk_smoothing/vtk_utils.cpp
@@ -49,6 +49,7 @@
 #include <vtkPolyData.h>
 #include <vtkPointData.h>
 #include <vtkFloatArray.h>
+#include <vtkUnsignedCharArray.h>
 
 // Support for VTK 7.1 upwards
 #ifdef vtkGenericDataArray_h
@@ -155,7 +156,11 @@ pcl::VTKUtils::vtk2mesh (const vtkSmartP
   }
 
   mesh.polygons.resize (nr_polygons);
+#ifdef VTK_CELL_ARRAY_V2
+  vtkIdType const *cell_points;
+#else
   vtkIdType* cell_points;
+#endif
   vtkIdType nr_cell_points;
   vtkCellArray * mesh_polygons = poly_data->GetPolys ();
   mesh_polygons->InitTraversal ();
