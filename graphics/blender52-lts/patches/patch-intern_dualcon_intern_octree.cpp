$NetBSD: patch-intern_dualcon_intern_octree.cpp,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- intern/dualcon/intern/octree.cpp.orig	2026-09-12 17:54:54.419635908 +0000
+++ intern/dualcon/intern/octree.cpp
@@ -2184,7 +2184,7 @@ static void pseudoInverse(const Eigen::Matrix3f &a, Ei
 static void pseudoInverse(const Eigen::Matrix3f &a, Eigen::Matrix3f &result, float tolerance)
 {
   const int Options = Eigen::ComputeFullU | Eigen::ComputeFullV;
-  Eigen::JacobiSVD<Eigen::Matrix3f, Options> svd = a.jacobiSvd<Options>();
+  Eigen::JacobiSVD<Eigen::Matrix3f> svd(a, Options);
 
   result = svd.matrixV() *
            Eigen::Vector3f((svd.singularValues().array().abs() > tolerance)
