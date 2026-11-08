$NetBSD: patch-intern_libmv_libmv_multiview_euclidean__resection.cc,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- intern/libmv/libmv/multiview/euclidean_resection.cc.orig	2026-09-12 18:00:09.276323596 +0000
+++ intern/libmv/libmv/multiview/euclidean_resection.cc
@@ -107,7 +107,7 @@ void AbsoluteOrientation(const Mat3X& X, const Mat3X& 
 
   // Find the unit quaternion q that maximizes qNq. It is the eigenvector
   // corresponding to the lagest eigenvalue.
-  Vec4 q = N.jacobiSvd<Eigen::ComputeFullU>().matrixU().col(0);
+  Vec4 q = N.jacobiSvd(Eigen::ComputeFullU).matrixU().col(0);
 
   // Retrieve the 3x3 rotation matrix.
   Vec4 qq = q.array() * q.array();
@@ -246,7 +246,7 @@ void EuclideanResectionAnsarDaniilidis(const Mat2X& x_
   }
 
   int num_lambda = num_points + 1;  // Dimension of the null space of M.
-  Mat V = M.jacobiSvd<Eigen::ComputeFullV>().matrixV().block(
+  Mat V = M.jacobiSvd(Eigen::ComputeFullV).matrixV().block(
       0, num_m_rows, num_m_columns, num_lambda);
 
   // TODO(vess): The number of constraint equations in K (num_k_rows) must be
@@ -303,7 +303,7 @@ void EuclideanResectionAnsarDaniilidis(const Mat2X& x_
     }
   }
   Vec L_sq =
-      K.jacobiSvd<Eigen::ComputeFullV>().matrixV().col(num_k_columns - 1);
+      K.jacobiSvd(Eigen::ComputeFullV).matrixV().col(num_k_columns - 1);
 
   // Pivot on the largest element for numerical stability. Afterwards recover
   // the sign of the lambda solution.
