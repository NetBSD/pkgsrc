$NetBSD: patch-Eigen_src_Core_IO.h,v 1.2 2023/03/29 08:55:00 wiz Exp $

Add missing includes
https://gitlab.com/libeigen/eigen/-/issues/2634

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
