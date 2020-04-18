$NetBSD: patch-Eigen_src_Core_IO.h,v 1.1 2020/04/18 22:01:57 joerg Exp $

--- Eigen/src/Core/IO.h.orig	2020-04-18 02:56:39.805274318 +0000
+++ Eigen/src/Core/IO.h
@@ -11,6 +11,9 @@
 #ifndef EIGEN_IO_H
 #define EIGEN_IO_H
 
+#include <ostream>
+#include <sstream>
+
 namespace Eigen { 
 
 enum { DontAlignCols = 1 };
