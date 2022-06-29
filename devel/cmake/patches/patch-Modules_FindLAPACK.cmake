$NetBSD: patch-Modules_FindLAPACK.cmake,v 1.1 2022/06/29 11:34:47 thor Exp $

Advance pkg-config usage for BLAS stuff, upstreamed to appear
in 3.25.

--- Modules/FindLAPACK.cmake.orig	2022-05-25 13:42:51.000000000 +0000
+++ Modules/FindLAPACK.cmake
@@ -35,6 +35,13 @@ The following variables may be set to in
   if set ``pkg-config`` will be used to search for a LAPACK library first
   and if one is found that is preferred
 
+``BLA_PKGCONFIG_LAPACK``
+  .. versionadded:: 3.25
+
+  If set, the ``pkg-config`` method will look for this module name instead of
+  just ``lapack``.
+
+
 ``BLA_SIZEOF_INTEGER``
   .. versionadded:: 3.22
 
@@ -278,8 +285,11 @@ endif()
 
 # Search with pkg-config if specified
 if(BLA_PREFER_PKGCONFIG)
+  if(NOT BLA_PKGCONFIG_LAPACK)
+    set(BLA_PKGCONFIG_LAPACK "lapack")
+  endif()
   find_package(PkgConfig)
-  pkg_check_modules(PKGC_LAPACK lapack)
+  pkg_check_modules(PKGC_LAPACK ${BLA_PKGCONFIG_LAPACK})
   if(PKGC_LAPACK_FOUND)
     set(LAPACK_FOUND TRUE)
     set(LAPACK_LIBRARIES "${PKGC_LAPACK_LINK_LIBRARIES}")
