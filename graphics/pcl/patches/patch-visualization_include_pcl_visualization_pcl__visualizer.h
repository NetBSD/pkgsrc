$NetBSD: patch-visualization_include_pcl_visualization_pcl__visualizer.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/pcl_visualizer.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/include/pcl/visualization/pcl_visualizer.h
@@ -53,14 +53,15 @@
 #include <pcl/visualization/area_picking_event.h>
 #include <pcl/visualization/interactor_style.h>
 
+#include <vtkOrientationMarkerWidget.h>
+#include <vtkRenderWindowInteractor.h>
+
 // VTK includes
 class vtkPolyData;
 class vtkTextActor;
 class vtkRenderWindow;
-class vtkOrientationMarkerWidget;
 class vtkAppendPolyData;
 class vtkRenderWindow;
-class vtkRenderWindowInteractor;
 class vtkTransform;
 class vtkInteractorStyle;
 class vtkLODActor;
@@ -68,6 +69,7 @@ class vtkProp;
 class vtkActor;
 class vtkDataSet;
 class vtkUnstructuredGrid;
+class vtkCellArray;
 
 namespace pcl
 {
@@ -76,6 +78,11 @@ namespace pcl
 
   namespace visualization
   {
+    namespace details
+    {
+      vtkIdType fillCells(std::vector<int>& lookup, const std::vector<pcl::Vertices>& vertices, vtkSmartPointer<vtkCellArray> cell_array, int max_size_of_polygon);
+    }
+
     /** \brief PCL Visualizer main class.
       * \author Radu B. Rusu
       * \ingroup visualization
@@ -2170,7 +2177,7 @@ namespace pcl
                                         vtkSmartPointer<vtkPolyData> &polydata,
                                         vtkSmartPointer<vtkIdTypeArray> &initcells);
 
-        /** \brief Converts a PCL templated PointCloud object to a vtk polydata object.
+        /** \brief Converts a PCL object to a vtk polydata object.
           * \param[in] geometry_handler the geometry handler object used to extract the XYZ data
           * \param[out] polydata the resultant polydata containing the cloud
           * \param[out] initcells a list of cell indices used for the conversion. This can be set once and then passed
