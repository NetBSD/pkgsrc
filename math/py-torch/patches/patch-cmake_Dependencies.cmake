$NetBSD: patch-cmake_Dependencies.cmake,v 1.2 2025/08/19 15:05:38 wiz Exp $

* Fix errors related to RPATH change.

--- cmake/Dependencies.cmake.orig	2024-10-29 18:00:43.000000000 +0000
+++ cmake/Dependencies.cmake
@@ -9,7 +9,7 @@ endif(APPLE)
 # Use separate rpaths during build and install phases
 set(CMAKE_SKIP_BUILD_RPATH  FALSE)
 # Don't use the install-rpath during the build phase
-set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
+set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
 set(CMAKE_INSTALL_RPATH "${_rpath_portable_origin}")
 # Automatically add all linked folders that are NOT in the build directory to
 # the rpath (per library?)
