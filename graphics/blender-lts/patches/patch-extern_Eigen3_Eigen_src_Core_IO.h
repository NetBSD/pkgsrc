$NetBSD: patch-extern_Eigen3_Eigen_src_Core_IO.h,v 1.2 2024/02/11 15:29:59 ryoon Exp $

--- extern/Eigen3/Eigen/src/Core/IO.h.orig	2020-02-13 11:33:22.000000000 +0000
+++ extern/Eigen3/Eigen/src/Core/IO.h
@@ -11,6 +11,9 @@
 #ifndef EIGEN_IO_H
 #define EIGEN_IO_H
 
+#include <ostream>
+#include <sstream>
+
 namespace Eigen { 
 
 enum { DontAlignCols = 1 };
