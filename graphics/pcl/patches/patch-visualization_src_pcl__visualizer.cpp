$NetBSD: patch-visualization_src_pcl__visualizer.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/src/pcl_visualizer.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/src/pcl_visualizer.cpp
@@ -51,7 +51,7 @@
 #include <vtkPolyDataNormals.h>
 #include <vtkMapper.h>
 #include <vtkDataSetMapper.h>
-
+#include <vtkCellArray.h>
 #include <vtkHardwareSelector.h>
 #include <vtkSelectionNode.h>
 
@@ -60,6 +60,7 @@
 
 #include <pcl/visualization/boost.h>
 #include <pcl/visualization/vtk/vtkRenderWindowInteractorFix.h>
+#include <pcl/visualization/vtk/pcl_vtk_compatibility.h>
 
 #if VTK_RENDERING_BACKEND_OPENGL_VERSION < 2
 #include <pcl/visualization/vtk/vtkVertexBufferObjectMapper.h>
@@ -82,7 +83,6 @@
 #include <vtkAxesActor.h>
 #include <vtkRenderWindowInteractor.h>
 #include <vtkAreaPicker.h>
-#include <vtkXYPlotActor.h>
 #include <vtkOpenGLRenderWindow.h>
 #include <vtkJPEGReader.h>
 #include <vtkBMPReader.h>
@@ -122,6 +122,63 @@
   #undef far
 #endif
 
+vtkIdType
+pcl::visualization::details::fillCells(std::vector<int>& lookup, const std::vector<pcl::Vertices>& vertices, vtkSmartPointer<vtkCellArray> cell_array, int max_size_of_polygon)
+{
+#ifdef VTK_CELL_ARRAY_V2
+  pcl::utils::ignore(max_size_of_polygon);
+
+  if (!lookup.empty())
+  {
+    for (const auto& verti : vertices)
+    {
+      std::size_t n_points = verti.vertices.size();
+      cell_array->InsertNextCell(n_points);
+      for (const auto& vertj : verti.vertices)
+        cell_array->InsertCellPoint(lookup[vertj]);
+    }
+  }
+  else
+  {
+    for (const auto& verti : vertices)
+    {
+      std::size_t n_points = verti.vertices.size();
+      cell_array->InsertNextCell(n_points);
+      for (const auto& vertj : verti.vertices)
+        cell_array->InsertCellPoint(vertj);
+    }
+  }
+#else
+  vtkIdType* cell = cell_array->WritePointer(vertices.size(), vertices.size() * (max_size_of_polygon + 1));
+
+  if (!lookup.empty())
+  {
+    for (const auto& verti : vertices)
+    {
+      std::size_t n_points = verti.vertices.size();
+      *cell++ = n_points;
+      for (const auto& vertj : verti.vertices)
+        *cell++ = lookup[vertj];
+    }
+  }
+  else
+  {
+    for (const auto& verti : vertices)
+    {
+      std::size_t n_points = verti.vertices.size();
+      *cell++ = n_points;
+      for (const auto& vertj : verti.vertices)
+        *cell++ = vertj;
+    }
+  }
+#endif
+
+  const auto idx = vertices.size() + std::accumulate(vertices.begin(), vertices.end(), static_cast<vtkIdType>(0),
+    [](const auto& sum, const auto& vertex) { return sum + vertex.vertices.size(); });
+
+  return idx;
+}
+
 /////////////////////////////////////////////////////////////////////////////////////////////
 pcl::visualization::PCLVisualizer::PCLVisualizer (const std::string &name, const bool create_interactor)
   : update_fps_ (vtkSmartPointer<FPSCallback>::New ())
@@ -521,13 +578,14 @@ void
 pcl::visualization::PCLVisualizer::spinOnce (int time, bool force_redraw)
 {
   resetStoppedFlag ();
-  #if (defined (__APPLE__))
-    if (!win_->IsDrawable ())
-    {
-      close ();
-      return;
-    }
-  #endif
+
+#if VTK_MAJOR_VERSION < 9 && defined (__APPLE__)
+  if (!win_->IsDrawable ())
+  {
+    close ();
+    return;
+  }
+#endif
 
   if (!interactor_)
     return;
@@ -1262,7 +1320,6 @@ pcl::visualization::PCLVisualizer::creat
   //actor->SetNumberOfCloudPoints (std::max<vtkIdType> (1, data->GetNumberOfPoints () / 10));
   actor->GetProperty ()->SetInterpolationToFlat ();
 }
-
 /////////////////////////////////////////////////////////////////////////////////////////////
 void
 pcl::visualization::PCLVisualizer::convertPointCloudToVTKPolyData (
@@ -1291,10 +1348,36 @@ pcl::visualization::PCLVisualizer::conve
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
 
 //////////////////////////////////////////////////////////////////////////////////////////////
@@ -3160,28 +3243,9 @@ pcl::visualization::PCLVisualizer::updat
 
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
@@ -3552,7 +3616,8 @@ pcl::visualization::PCLVisualizer::rende
 
   //center object
   double CoM[3];
-  vtkIdType npts_com = 0, *ptIds_com = nullptr;
+  vtkIdType npts_com = 0;
+  vtkCellPtsPtr ptIds_com = nullptr;
   vtkSmartPointer<vtkCellArray> cells_com = polydata->GetPolys ();
 
   double center[3], p1_com[3], p2_com[3], p3_com[3], totalArea_com = 0;
@@ -3611,10 +3676,11 @@ pcl::visualization::PCLVisualizer::rende
   // * Compute area of the mesh
   //////////////////////////////
   vtkSmartPointer<vtkCellArray> cells = mapper->GetInput ()->GetPolys ();
-  vtkIdType npts = 0, *ptIds = nullptr;
+  vtkIdType npts = 0;
+  vtkCellPtsPtr ptIds = nullptr;
 
   double p1[3], p2[3], p3[3], totalArea = 0;
-  for (cells->InitTraversal (); cells->GetNextCell (npts, ptIds);)
+  for (cells->InitTraversal (); cells->GetNextCell(npts, ptIds);)
   {
     polydata->GetPoint (ptIds[0], p1);
     polydata->GetPoint (ptIds[1], p2);
@@ -3830,7 +3896,8 @@ pcl::visualization::PCLVisualizer::rende
     polydata->BuildCells ();
 
     vtkSmartPointer<vtkCellArray> cells = polydata->GetPolys ();
-    vtkIdType npts = 0, *ptIds = nullptr;
+    vtkIdType npts = 0;
+    vtkCellPtsPtr ptIds = nullptr;
 
     double p1[3], p2[3], p3[3], area, totalArea = 0;
     for (cells->InitTraversal (); cells->GetNextCell (npts, ptIds);)
@@ -4040,9 +4107,9 @@ pcl::visualization::PCLVisualizer::fromH
 
   vtkSmartPointer<vtkPolyData> polydata;
   vtkSmartPointer<vtkIdTypeArray> initcells;
+
   // Convert the PointCloud to VTK PolyData
   convertPointCloudToVTKPolyData (geometry_handler, polydata, initcells);
-  // use the given geometry handler
 
   // Get the colors from the handler
   bool has_colors = false;
