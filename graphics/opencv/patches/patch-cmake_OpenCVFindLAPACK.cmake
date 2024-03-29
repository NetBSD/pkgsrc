$NetBSD: patch-cmake_OpenCVFindLAPACK.cmake,v 1.2 2023/12/22 15:35:44 thor Exp $

--- cmake/OpenCVFindLAPACK.cmake.orig	2021-12-24 16:39:15.000000000 +0000
+++ cmake/OpenCVFindLAPACK.cmake
@@ -52,6 +52,9 @@ macro(ocv_lapack_check)
       list(APPEND _lapack_content "#include \"${OPENCV_LAPACKE_H_PATH_${_lapack_impl}}\"")
     endif()
     list(APPEND _lapack_content "
+/* avoid name clashes with older gcc, alias to _Complex breaking std::complex */
+#undef complex
+
 #if defined(LAPACK_GLOBAL) || defined(LAPACK_NAME)
 /*
  * Using netlib's reference LAPACK implementation version >= 3.4.0 (first with C interface).
@@ -84,7 +87,7 @@ macro(ocv_lapack_check)
         OUTPUT_VARIABLE TRY_OUT
     )
     if(NOT __VALID_LAPACK)
-      #message(FATAL_ERROR "LAPACK: check build log:\n${TRY_OUT}")
+      message(FATAL_ERROR "LAPACK: check build log:\n${TRY_OUT}")
       message(STATUS "LAPACK(${LAPACK_IMPL}): Can't build LAPACK check code. This LAPACK version is not supported.")
       unset(LAPACK_LIBRARIES)
     else()
@@ -98,6 +101,22 @@ endmacro()
 if(WITH_LAPACK)
   ocv_update(LAPACK_IMPL "Unknown")
   if(NOT OPENCV_LAPACK_FIND_PACKAGE_ONLY)
+    # Mimicking cmake's FindBLAS with BLA_PREFER_PKGCONFIG
+    if(NOT LAPACK_LIBRARIES AND BLA_PREFER_PKGCONFIG)
+       find_package(PkgConfig)
+       pkg_search_module(PKG_BLAS ${BLA_PKGCONFIG_BLAS} blas)
+       pkg_search_module(PKG_LAPACK ${BLA_PKGCONFIG_LAPACK} lapack)
+       pkg_search_module(PKG_CBLAS ${BLA_PKGCONFIG_CBLAS} cblas)
+       pkg_search_module(PKG_LAPACKE ${BLA_PKGCONFIG_LAPACKE} lapacke)
+       if(PKG_BLAS_FOUND AND PKG_LAPACK_FOUND AND PKG_CBLAS_FOUND AND PKG_LAPACKE_FOUND)
+          set(LAPACK_INCLUDE_DIR ${PKG_CBLAS_INCLUDE_DIRS} ${PKG_LAPACKE_INCLUDE_DIRS} ${PKG_BLAS_INCLUDE_DIRS} ${PKG_LAPACK_INCLUDE_DIRS})
+          set(LAPACK_LIBRARIES ${PKG_CBLAS_LIBRARIES} ${PKG_LAPACKE_LIBRARIES} ${PKG_BLAS_LIBRARIES} ${PKG_LAPACK_LIBRARIES})
+          set(LAPACK_CBLAS_H   "cblas.h")
+          set(LAPACK_LAPACKE_H "lapacke.h")
+          set(LAPACK_IMPL      "pkg")
+          ocv_lapack_check()
+       endif()
+    endif()
     if(NOT LAPACK_LIBRARIES AND NOT OPENCV_LAPACK_DISABLE_MKL)
       include(cmake/OpenCVFindMKL.cmake)
       if(HAVE_MKL)
