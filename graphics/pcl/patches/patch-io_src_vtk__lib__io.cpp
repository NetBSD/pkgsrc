$NetBSD: patch-io_src_vtk__lib__io.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- io/src/vtk_lib_io.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ io/src/vtk_lib_io.cpp
@@ -343,7 +343,11 @@ pcl::io::vtk2mesh (const vtkSmartPointer
 
   // Now handle the polygons
   mesh.polygons.resize (nr_polygons);
+#ifdef VTK_CELL_ARRAY_V2
+  vtkIdType const *cell_points;
+#else
   vtkIdType* cell_points;
+#endif
   vtkIdType nr_cell_points;
   vtkCellArray * mesh_polygons = poly_data->GetPolys ();
   mesh_polygons->InitTraversal ();
