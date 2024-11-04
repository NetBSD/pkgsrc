$NetBSD: patch-src_cmake_externalpackages.cmake,v 1.3 2024/11/04 21:22:23 adam Exp $

Boost from pkgsrc doesn't have cmake configuration files.

--- src/cmake/externalpackages.cmake.orig	2024-11-04 20:08:07.142125120 +0000
+++ src/cmake/externalpackages.cmake
@@ -34,9 +34,6 @@ include (FindThreads)
 
 ###########################################################################
 # Boost setup
-if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.30")
-    set (boost_config CONFIG)
-endif ()
 if (MSVC)
     # Disable automatic linking using pragma comment(lib,...) of boost libraries upon including of a header
     add_definitions (-DBOOST_ALL_NO_LIB=1)
