$NetBSD: patch-Modules_FindBLAS.cmake,v 1.1 2022/06/29 11:34:47 thor Exp $

Advance pkg-config usage for BLAS stuff, upstreamed to appear
in 3.25.

--- Modules/FindBLAS.cmake.orig	2022-05-25 13:42:51.000000000 +0000
+++ Modules/FindBLAS.cmake
@@ -35,6 +35,12 @@ The following variables may be set to in
   if set ``pkg-config`` will be used to search for a BLAS library first
   and if one is found that is preferred
 
+``BLA_PKGCONFIG_BLAS``
+  .. versionadded:: 3.25
+
+  If set, the ``pkg-config`` method will look for this module name instead of
+  just ``blas``.
+
 ``BLA_SIZEOF_INTEGER``
   .. versionadded:: 3.22
 
@@ -273,8 +279,11 @@ endif()
 include(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)
 
 if(BLA_PREFER_PKGCONFIG)
+  if(NOT BLA_PKGCONFIG_BLAS)
+    set(BLA_PKGCONFIG_BLAS "blas")
+  endif()
   find_package(PkgConfig)
-  pkg_check_modules(PKGC_BLAS blas)
+  pkg_check_modules(PKGC_BLAS ${BLA_PKGCONFIG_BLAS})
   if(PKGC_BLAS_FOUND)
     set(BLAS_FOUND ${PKGC_BLAS_FOUND})
     set(BLAS_LIBRARIES "${PKGC_BLAS_LINK_LIBRARIES}")
