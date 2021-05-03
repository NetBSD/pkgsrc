$NetBSD: patch-surface_include_pcl_surface_impl_convex__hull.hpp,v 1.1 2021/05/03 06:25:11 thor Exp $

Support current qhull (from PR 4540).

--- surface/include/pcl/surface/impl/convex_hull.hpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ surface/include/pcl/surface/impl/convex_hull.hpp
@@ -180,18 +180,23 @@ pcl::ConvexHull<PointInT>::performRecons
     // This should only happen if we had invalid input
     PCL_ERROR ("[pcl::%s::performReconstruction2D] Invalid input!\n", getClassName ().c_str ());
   }
+
+  qhT qh_qh;
+  qhT* qh = &qh_qh;
+  QHULL_LIB_CHECK
+  qh_zero(qh, errfile);
    
   // Compute convex hull
-  int exitcode = qh_new_qhull (dimension, static_cast<int> (indices_->size ()), points, ismalloc, const_cast<char*> (flags), outfile, errfile);
+  int exitcode = qh_new_qhull (qh, dimension, static_cast<int> (indices_->size ()), points, ismalloc, const_cast<char*> (flags), outfile, errfile);
 #ifdef HAVE_QHULL_2011
   if (compute_area_)
   {
-    qh_prepare_output();
+    qh_prepare_output(qh);
   }
 #endif
     
   // 0 if no error from qhull or it doesn't find any vertices
-  if (exitcode != 0 || qh num_vertices == 0)
+  if (exitcode != 0 || qh->num_vertices == 0)
   {
     PCL_ERROR ("[pcl::%s::performReconstrution2D] ERROR: qhull was unable to compute a convex hull for the given point cloud (%lu)!\n", getClassName ().c_str (), indices_->size ());
 
@@ -199,9 +204,9 @@ pcl::ConvexHull<PointInT>::performRecons
     hull.width = hull.height = 0;
     polygons.resize (0);
 
-    qh_freeqhull (!qh_ALL);
+    qh_freeqhull (qh, !qh_ALL);
     int curlong, totlong;
-    qh_memfreeshort (&curlong, &totlong);
+    qh_memfreeshort (qh, &curlong, &totlong);
 
     return;
   }
@@ -209,11 +214,11 @@ pcl::ConvexHull<PointInT>::performRecons
   // Qhull returns the area in volume for 2D
   if (compute_area_)
   {
-    total_area_ = qh totvol;
+    total_area_ = qh->totvol;
     total_volume_ = 0.0;
   }
 
-  int num_vertices = qh num_vertices;
+  int num_vertices = qh->num_vertices;
   hull.points.resize (num_vertices);
   memset (&hull.points[0], hull.size (), sizeof (PointInT));
 
@@ -226,8 +231,8 @@ pcl::ConvexHull<PointInT>::performRecons
 
   FORALLvertices
   {
-    hull[i] = (*input_)[(*indices_)[qh_pointid (vertex->point)]];
-    idx_points[i].first = qh_pointid (vertex->point);
+    hull[i] = (*input_)[(*indices_)[qh_pointid (qh, vertex->point)]];
+    idx_points[i].first = qh_pointid (qh, vertex->point);
     ++i;
   }
 
@@ -274,9 +279,9 @@ pcl::ConvexHull<PointInT>::performRecons
     polygons[0].vertices[j] = static_cast<unsigned int> (j);
   }
     
-  qh_freeqhull (!qh_ALL);
+  qh_freeqhull (qh, !qh_ALL);
   int curlong, totlong;
-  qh_memfreeshort (&curlong, &totlong);
+  qh_memfreeshort (qh, &curlong, &totlong);
 
   hull.width = hull.size ();
   hull.height = 1;
@@ -320,12 +325,19 @@ pcl::ConvexHull<PointInT>::performRecons
     points[j + 2] = static_cast<coordT> ((*input_)[(*indices_)[i]].z);
   }
 
+  static FILE* null = fopen("/dev/null", "w");
+
+  qhT qh_qh;
+  qhT* qh = &qh_qh;
+  QHULL_LIB_CHECK
+  qh_zero(qh, null);
+
   // Compute convex hull
-  int exitcode = qh_new_qhull (dimension, static_cast<int> (indices_->size ()), points, ismalloc, const_cast<char*> (flags), outfile, errfile);
+  int exitcode = qh_new_qhull (qh, dimension, static_cast<int> (indices_->size ()), points, ismalloc, const_cast<char*> (flags), outfile, errfile);
 #ifdef HAVE_QHULL_2011
   if (compute_area_)
   {
-    qh_prepare_output();
+    qh_prepare_output(qh);
   }
 #endif
 
@@ -341,18 +353,18 @@ pcl::ConvexHull<PointInT>::performRecons
     hull.width = hull.height = 0;
     polygons.resize (0);
 
-    qh_freeqhull (!qh_ALL);
+    qh_freeqhull (qh, !qh_ALL);
     int curlong, totlong;
-    qh_memfreeshort (&curlong, &totlong);
+    qh_memfreeshort (qh, &curlong, &totlong);
 
     return;
   }
 
-  qh_triangulate ();
+  qh_triangulate (qh);
 
-  int num_facets = qh num_facets;
+  int num_facets = qh->num_facets;
 
-  int num_vertices = qh num_vertices;
+  int num_vertices = qh->num_vertices;
   hull.points.resize (num_vertices);
 
   vertexT * vertex;
@@ -375,7 +387,7 @@ pcl::ConvexHull<PointInT>::performRecons
   FORALLvertices
   {
     // Add vertices to hull point_cloud and store index
-    hull_indices_.indices.push_back ((*indices_)[qh_pointid (vertex->point)]);
+    hull_indices_.indices.push_back ((*indices_)[qh_pointid (qh, vertex->point)]);
     hull[i] = (*input_)[hull_indices_.indices.back ()];
 
     qhid_to_pcidx[vertex->id] = i; // map the vertex id of qhull to the point cloud index
@@ -384,8 +396,8 @@ pcl::ConvexHull<PointInT>::performRecons
 
   if (compute_area_)
   {
-    total_area_  = qh totarea;
-    total_volume_ = qh totvol;
+    total_area_  = qh->totarea;
+    total_volume_ = qh->totvol;
   }
 
   if (fill_polygon_data)
@@ -400,16 +412,16 @@ pcl::ConvexHull<PointInT>::performRecons
 
       // Needed by FOREACHvertex_i_
       int vertex_n, vertex_i;
-      FOREACHvertex_i_ ((*facet).vertices)
+      FOREACHvertex_i_ (qh, (*facet).vertices)
       //facet_vertices.vertices.push_back (qhid_to_pcidx[vertex->id]);
       polygons[dd].vertices[vertex_i] = qhid_to_pcidx[vertex->id];
       ++dd;
     }
   }
   // Deallocates memory (also the points)
-  qh_freeqhull (!qh_ALL);
+  qh_freeqhull (qh, !qh_ALL);
   int curlong, totlong;
-  qh_memfreeshort (&curlong, &totlong);
+  qh_memfreeshort (qh, &curlong, &totlong);
 
   hull.width = hull.size ();
   hull.height = 1;
