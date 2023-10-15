$NetBSD: patch-share_cmake_modules_Findyaml-cpp.cmake,v 1.1 2023/10/15 19:45:33 ryoon Exp $

* Fix yaml-cpp-0.8.8 detection.

--- share/cmake/modules/Findyaml-cpp.cmake.orig	2023-01-06 02:05:59.000000000 +0000
+++ share/cmake/modules/Findyaml-cpp.cmake
@@ -39,7 +39,7 @@ if(NOT OCIO_INSTALL_EXT_PACKAGES STREQUA
 
     if(NOT DEFINED yaml-cpp_ROOT)
         # Search for yaml-cpp-config.cmake
-        find_package(yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG QUIET)
+        find_package(yaml-cpp::yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG QUIET)
     endif()
 
     if(yaml-cpp_FOUND)
