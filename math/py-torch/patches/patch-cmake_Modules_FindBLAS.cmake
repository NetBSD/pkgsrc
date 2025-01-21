$NetBSD: patch-cmake_Modules_FindBLAS.cmake,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Find blas from pkgsrc.
  XXX: Using BLAS_PC here is completely incorrect.

--- cmake/Modules/FindBLAS.cmake.orig	2025-01-17 11:19:26.996442468 +0000
+++ cmake/Modules/FindBLAS.cmake
@@ -172,7 +172,7 @@ if((NOT BLAS_LIBRARIES)
   BLAS
   sgemm
   ""
-  "openblas")
+  "@BLAS_PC@")
   if(BLAS_LIBRARIES)
     set(BLAS_INFO "open")
   endif(BLAS_LIBRARIES)
