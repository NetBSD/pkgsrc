$NetBSD: patch-cmake_cares.cmake,v 1.1 2018/04/27 17:47:27 minskim Exp $

Find libcares from pkgsrc.

--- cmake/cares.cmake.orig	2018-04-13 18:08:11.000000000 +0000
+++ cmake/cares.cmake
@@ -31,10 +31,11 @@ if("${gRPC_CARES_PROVIDER}" STREQUAL "mo
   endif()
 elseif("${gRPC_CARES_PROVIDER}" STREQUAL "package")
   # Use "CONFIG" as there is no built-in cmake module for c-ares.
-  find_package(c-ares REQUIRED CONFIG)
-  if(TARGET c-ares::cares)
-    set(_gRPC_CARES_LIBRARIES c-ares::cares)
-    set(_gRPC_CARES_INCLUDE_DIR ${c-ares_INCLUDE_DIR})
+  find_package(PkgConfig REQUIRED)
+  pkg_search_module(cares REQUIRED IMPORTED_TARGET libcares)
+  if(TARGET PkgConfig::cares)
+    set(_gRPC_CARES_LIBRARIES PkgConfig::cares)
+    set(_gRPC_CARES_INCLUDE_DIR ${cares_INCLUDE_DIRS})
   endif()
   set(_gRPC_FIND_CARES "if(NOT c-ares_FOUND)\n  find_package(c-ares CONFIG)\nendif()")
 endif()
