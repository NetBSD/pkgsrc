$NetBSD: patch-surface_include_pcl_surface_impl_concave__hull.hpp,v 1.1 2021/05/03 06:25:11 thor Exp $

Support current qhull (from PR 4540).

--- surface/include/pcl/surface/impl/concave_hull.hpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ surface/include/pcl/surface/impl/concave_hull.hpp
@@ -194,8 +194,13 @@ pcl::ConcaveHull<PointInT>::performRecon
       points[i * dim_ + 2] = static_cast<coordT> (cloud_transformed[i].z);
   }
 
+  qhT qh_qh;
+  qhT* qh = &qh_qh;
+  QHULL_LIB_CHECK
+  qh_zero(qh, errfile);
+
   // Compute concave hull
-  exitcode = qh_new_qhull (dim_, static_cast<int> (cloud_transformed.size ()), points, ismalloc, flags, outfile, errfile);
+  exitcode = qh_new_qhull (qh, dim_, static_cast<int> (cloud_transformed.size ()), points, ismalloc, flags, outfile, errfile);
 
   if (exitcode != 0)
   {
@@ -227,16 +232,16 @@ pcl::ConcaveHull<PointInT>::performRecon
     alpha_shape.width = alpha_shape.height = 0;
     polygons.resize (0);
 
-    qh_freeqhull (!qh_ALL);
+    qh_freeqhull (qh, !qh_ALL);
     int curlong, totlong;
-    qh_memfreeshort (&curlong, &totlong);
+    qh_memfreeshort (qh, &curlong, &totlong);
 
     return;
   }
 
-  qh_setvoronoi_all ();
+  qh_setvoronoi_all (qh);
 
-  int num_vertices = qh num_vertices;
+  int num_vertices = qh->num_vertices;
   alpha_shape.points.resize (num_vertices);
 
   vertexT *vertex;
@@ -253,11 +258,11 @@ pcl::ConcaveHull<PointInT>::performRecon
   ++max_vertex_id;
   std::vector<int> qhid_to_pcidx (max_vertex_id);
 
-  int num_facets = qh num_facets;
+  int num_facets = qh->num_facets;
 
   if (dim_ == 3)
   {
-    setT *triangles_set = qh_settemp (4 * num_facets);
+    setT *triangles_set = qh_settemp (qh, 4 * num_facets);
     if (voronoi_centers_)
       voronoi_centers_->points.resize (num_facets);
 
@@ -283,29 +288,29 @@ pcl::ConcaveHull<PointInT>::performRecon
         if (r <= alpha_)
         {
           // all triangles in tetrahedron are good, add them all to the alpha shape (triangles_set)
-          qh_makeridges (facet);
+          qh_makeridges (qh, facet);
           facet->good = true;
-          facet->visitid = qh visit_id;
+          facet->visitid = qh->visit_id;
           ridgeT *ridge, **ridgep;
           FOREACHridge_ (facet->ridges)
           {
             facetT *neighb = otherfacet_ (ridge, facet);
-            if ((neighb->visitid != qh visit_id))
-              qh_setappend (&triangles_set, ridge);
+            if ((neighb->visitid != qh->visit_id))
+              qh_setappend (qh, &triangles_set, ridge);
           }
         }
         else
         {
           // consider individual triangles from the tetrahedron...
           facet->good = false;
-          facet->visitid = qh visit_id;
-          qh_makeridges (facet);
+          facet->visitid = qh->visit_id;
+          qh_makeridges (qh, facet);
           ridgeT *ridge, **ridgep;
           FOREACHridge_ (facet->ridges)
           {
             facetT *neighb;
             neighb = otherfacet_ (ridge, facet);
-            if ((neighb->visitid != qh visit_id))
+            if ((neighb->visitid != qh->visit_id))
             {
               // check if individual triangle is good and add it to triangles_set
 
@@ -322,7 +327,7 @@ pcl::ConcaveHull<PointInT>::performRecon
 
               double r = pcl::getCircumcircleRadius (a, b, c);
               if (r <= alpha_)
-                qh_setappend (&triangles_set, ridge);
+                qh_setappend (qh, &triangles_set, ridge);
             }
           }
         }
@@ -354,7 +359,7 @@ pcl::ConcaveHull<PointInT>::performRecon
       {
         polygons[triangles].vertices.resize (3);
         int vertex_n, vertex_i;
-        FOREACHvertex_i_ ((*ridge).vertices)  //3 vertices per ridge!
+        FOREACHvertex_i_ (qh, (*ridge).vertices)  //3 vertices per ridge!
         {
           if (!added_vertices[vertex->id])
           {
@@ -383,7 +388,7 @@ pcl::ConcaveHull<PointInT>::performRecon
   {
     // Compute the alpha complex for the set of points
     // Filters the delaunay triangles
-    setT *edges_set = qh_settemp (3 * num_facets);
+    setT *edges_set = qh_settemp (qh, 3 * num_facets);
     if (voronoi_centers_)
       voronoi_centers_->points.resize (num_facets);
 
@@ -403,12 +408,12 @@ pcl::ConcaveHull<PointInT>::performRecon
         if (r <= alpha_)
         {
           pcl::Vertices facet_vertices;   //TODO: is not used!!
-          qh_makeridges (facet);
+          qh_makeridges (qh, facet);
           facet->good = true;
 
           ridgeT *ridge, **ridgep;
           FOREACHridge_ (facet->ridges)
-          qh_setappend (&edges_set, ridge);
+          qh_setappend (qh, &edges_set, ridge);
 
           if (voronoi_centers_)
           {
@@ -438,7 +443,7 @@ pcl::ConcaveHull<PointInT>::performRecon
         std::vector<int> pcd_indices;
         pcd_indices.resize (2);
 
-        FOREACHvertex_i_ ((*ridge).vertices)  //in 2-dim, 2 vertices per ridge!
+        FOREACHvertex_i_ (qh, (*ridge).vertices)  //in 2-dim, 2 vertices per ridge!
         {
           if (!added_vertices[vertex->id])
           {
@@ -540,9 +545,9 @@ pcl::ConcaveHull<PointInT>::performRecon
       voronoi_centers_->points.resize (dd);
   }
 
-  qh_freeqhull (!qh_ALL);
+  qh_freeqhull (qh, !qh_ALL);
   int curlong, totlong;
-  qh_memfreeshort (&curlong, &totlong);
+  qh_memfreeshort (qh, &curlong, &totlong);
 
   Eigen::Affine3d transInverse = transform1.inverse ();
   pcl::transformPointCloud (alpha_shape, alpha_shape, transInverse);
