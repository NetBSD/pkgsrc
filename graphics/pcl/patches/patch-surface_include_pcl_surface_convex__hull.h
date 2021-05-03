$NetBSD: patch-surface_include_pcl_surface_convex__hull.h,v 1.1 2021/05/03 06:25:11 thor Exp $

Support current qhull (from PR 4540).

--- surface/include/pcl/surface/convex_hull.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ surface/include/pcl/surface/convex_hull.h
@@ -89,11 +89,11 @@ namespace pcl
       using PointCloudConstPtr = typename PointCloud::ConstPtr;
 
       /** \brief Empty constructor. */
-      ConvexHull () : compute_area_ (false), total_area_ (0), total_volume_ (0), dimension_ (0), 
+      ConvexHull () : compute_area_ (false), total_area_ (0), total_volume_ (0), dimension_ (0),
                       projection_angle_thresh_ (std::cos (0.174532925) ), qhull_flags ("qhull "),
                       x_axis_ (1.0, 0.0, 0.0), y_axis_ (0.0, 1.0, 0.0), z_axis_ (0.0, 0.0, 1.0)
       {
-      };
+      }
       
       /** \brief Empty destructor */
       ~ConvexHull () {}
