$NetBSD: patch-extern_Eigen3_Eigen_src_Core_arch_CUDA_Half.h,v 1.2 2024/02/11 15:29:59 ryoon Exp $

--- extern/Eigen3/Eigen/src/Core/arch/CUDA/Half.h.orig	2020-02-13 11:33:22.000000000 +0000
+++ extern/Eigen3/Eigen/src/Core/arch/CUDA/Half.h
@@ -42,6 +42,7 @@
 #define EIGEN_EXPLICIT_CAST(tgt_type) operator tgt_type()
 #endif
 
+#include <ostream>
 
 namespace Eigen {
 
