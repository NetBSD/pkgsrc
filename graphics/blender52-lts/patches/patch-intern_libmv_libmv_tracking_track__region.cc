$NetBSD: patch-intern_libmv_libmv_tracking_track__region.cc,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- intern/libmv/libmv/tracking/track_region.cc.orig	2026-09-12 18:41:41.933251571 +0000
+++ intern/libmv/libmv/tracking/track_region.cc
@@ -940,7 +940,7 @@ struct AffineWarp {
     }
 
     // TODO(keir): Check solution quality.
-    Vec4 a = Q1.jacobiSvd<Eigen::ComputeThinU | Eigen::ComputeThinV>().solve(Q2);
+    Vec4 a = Q1.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(Q2);
     parameters[2] = a[0];
     parameters[3] = a[1];
     parameters[4] = a[2];
