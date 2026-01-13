$NetBSD: patch-share_cmake_modules_Findyaml-cpp.cmake,v 1.3 2026/01/13 11:57:54 adam Exp $

Fix yaml-cpp-0.8.0 detection.

--- share/cmake/modules/Findyaml-cpp.cmake.orig	2026-01-13 03:55:53.000000000 +0000
+++ share/cmake/modules/Findyaml-cpp.cmake
@@ -44,7 +44,7 @@ if(NOT OCIO_INSTALL_EXT_PACKAGES STREQUA
     set(_yaml-cpp_REQUIRED_VARS yaml-cpp_LIBRARY)
 
     # Search for yaml-cpp-config.cmake
-    find_package(yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG ${quiet})
+    find_package(yaml-cpp::yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG ${quiet})
 
     if(yaml-cpp_FOUND)
         # Alias target for yaml-cpp < 0.8 compatibility
