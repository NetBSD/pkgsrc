$NetBSD: patch-visualization_include_pcl_visualization_impl_pcl__visualizer.hpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/impl/pcl_visualizer.hpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/include/pcl/visualization/impl/pcl_visualizer.hpp
@@ -62,6 +62,7 @@
 #include <vtkLODActor.h>
 #include <vtkLineSource.h>
 
+#include <pcl/common/utils.h> // pcl::utils::ignore
 #include <pcl/visualization/common/shapes.h>
 
 // Support for VTK 7.1 upwards
@@ -270,11 +271,40 @@ pcl::visualization::PCLVisualizer::conve
     points->SetNumberOfPoints (nr_points);
   }
 
+#ifdef VTK_CELL_ARRAY_V2
+  // TODO: Remove when VTK 6,7,8 is unsupported
+  pcl::utils::ignore(initcells);
+
+  auto numOfCells = vertices->GetNumberOfCells();
+
+  // If we have less cells than points, add new cells.
+  if (numOfCells < nr_points)
+  {
+    for (int i = numOfCells; i < nr_points; i++)
+    {
+      vertices->InsertNextCell(1);
+      vertices->InsertCellPoint(i);
+    }
+  }
+  // if we too many cells than points, set size (doesn't free excessive memory)
+  else if (numOfCells > nr_points)
+  {
+    vertices->ResizeExact(nr_points, nr_points);
+  }
+
+  polydata->SetPoints(points);
+  polydata->SetVerts(vertices);
+
+#else
   vtkSmartPointer<vtkIdTypeArray> cells = vertices->GetData ();
   updateCells (cells, initcells, nr_points);
 
   // Set the cells and the vertices
   vertices->SetCells (nr_points, cells);
+
+  // Set the cell count explicitly as the array doesn't get modified enough so the above method updates accordingly. See #4001 and #3452
+  vertices->SetNumberOfCells(nr_points);
+#endif
 }
 
 //////////////////////////////////////////////////////////////////////////////////////////////
@@ -304,10 +334,36 @@ pcl::visualization::PCLVisualizer::conve
   if (!vertices)
     vertices = vtkSmartPointer<vtkCellArray>::New ();
 
+#ifdef VTK_CELL_ARRAY_V2
+  // TODO: Remove when VTK 6,7,8 is unsupported
+  pcl::utils::ignore(initcells);
+
+  auto numOfCells = vertices->GetNumberOfCells();
+
+  // If we have less cells than points, add new cells.
+  if (numOfCells < nr_points)
+  {
+    for (int i = numOfCells; i < nr_points; i++)
+    {
+      vertices->InsertNextCell(1);
+      vertices->InsertCellPoint(i);
+    }
+  }
+  // if we too many cells than points, set size (doesn't free excessive memory)
+  else if (numOfCells > nr_points)
+  {
+    vertices->ResizeExact(nr_points, nr_points);
+  }
+
+  polydata->SetPoints(points);
+  polydata->SetVerts(vertices);
+
+#else
   vtkSmartPointer<vtkIdTypeArray> cells = vertices->GetData ();
   updateCells (cells, initcells, nr_points);
   // Set the cells and the vertices
   vertices->SetCells (nr_points, cells);
+#endif
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////
@@ -1304,7 +1360,6 @@ pcl::visualization::PCLVisualizer::fromH
   vtkSmartPointer<vtkIdTypeArray> initcells;
   // Convert the PointCloud to VTK PolyData
   convertPointCloudToVTKPolyData<PointT> (geometry_handler, polydata, initcells);
-  // use the given geometry handler
 
   // Get the colors from the handler
   bool has_colors = false;
@@ -1701,32 +1756,9 @@ pcl::visualization::PCLVisualizer::addPo
   {
     // Create polys from polyMesh.polygons
     vtkSmartPointer<vtkCellArray> cell_array = vtkSmartPointer<vtkCellArray>::New ();
-    vtkIdType *cell = cell_array->WritePointer (vertices.size (), vertices.size () * (max_size_of_polygon + 1));
-    int idx = 0;
-    if (!lookup.empty ())
-    {
-      for (std::size_t i = 0; i < vertices.size (); ++i, ++idx)
-      {
-        std::size_t n_points = vertices[i].vertices.size ();
-        *cell++ = n_points;
-        //cell_array->InsertNextCell (n_points);
-        for (std::size_t j = 0; j < n_points; j++, ++idx)
-          *cell++ = lookup[vertices[i].vertices[j]];
-          //cell_array->InsertCellPoint (lookup[vertices[i].vertices[j]]);
-      }
-    }
-    else
-    {
-      for (std::size_t i = 0; i < vertices.size (); ++i, ++idx)
-      {
-        std::size_t n_points = vertices[i].vertices.size ();
-        *cell++ = n_points;
-        //cell_array->InsertNextCell (n_points);
-        for (std::size_t j = 0; j < n_points; j++, ++idx)
-          *cell++ = vertices[i].vertices[j];
-          //cell_array->InsertCellPoint (vertices[i].vertices[j]);
-      }
-    }
+    
+    const auto idx = details::fillCells(lookup,vertices,cell_array, max_size_of_polygon);
+
     vtkSmartPointer<vtkPolyData> polydata;
     allocVtkPolyData (polydata);
     cell_array->GetData ()->SetNumberOfValues (idx);
@@ -1878,28 +1910,9 @@ pcl::visualization::PCLVisualizer::updat
 
   // Update the cells
   cells = vtkSmartPointer<vtkCellArray>::New ();
-  vtkIdType *cell = cells->WritePointer (verts.size (), verts.size () * (max_size_of_polygon + 1));
-  int idx = 0;
-  if (!lookup.empty ())
-  {
-    for (std::size_t i = 0; i < verts.size (); ++i, ++idx)
-    {
-      std::size_t n_points = verts[i].vertices.size ();
-      *cell++ = n_points;
-      for (std::size_t j = 0; j < n_points; j++, cell++, ++idx)
-        *cell = lookup[verts[i].vertices[j]];
-    }
-  }
-  else
-  {
-    for (std::size_t i = 0; i < verts.size (); ++i, ++idx)
-    {
-      std::size_t n_points = verts[i].vertices.size ();
-      *cell++ = n_points;
-      for (std::size_t j = 0; j < n_points; j++, cell++, ++idx)
-        *cell = verts[i].vertices[j];
-    }
-  }
+  
+  const auto idx = details::fillCells(lookup, verts, cells, max_size_of_polygon);
+
   cells->GetData ()->SetNumberOfValues (idx);
   cells->Squeeze ();
   // Set the the vertices
