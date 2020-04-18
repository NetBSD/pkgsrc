$NetBSD: patch-Eigen_src_Core_arch_CUDA_Half.h,v 1.1 2020/04/18 22:01:57 joerg Exp $

--- Eigen/src/Core/arch/CUDA/Half.h.orig	2020-04-18 02:57:48.859229525 +0000
+++ Eigen/src/Core/arch/CUDA/Half.h
@@ -42,6 +42,7 @@
 #define EIGEN_EXPLICIT_CAST(tgt_type) operator tgt_type()
 #endif
 
+#include <ostream>
 
 namespace Eigen {
 
