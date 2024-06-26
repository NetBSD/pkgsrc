$NetBSD: patch-share_cmake_modules_Findyaml-cpp.cmake,v 1.2 2024/06/26 16:20:55 adam Exp $

Fix yaml-cpp-0.8.8 detection.

--- share/cmake/modules/Findyaml-cpp.cmake.orig	2024-01-30 07:11:35.000000000 +0000
+++ share/cmake/modules/Findyaml-cpp.cmake
@@ -49,7 +49,7 @@ if(NOT OCIO_INSTALL_EXT_PACKAGES STREQUA
 
     # Search for yaml-cpp-config.cmake
     if(NOT DEFINED yaml-cpp_ROOT)
-        find_package(yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG ${quiet})
+        find_package(yaml-cpp::yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG ${quiet})
     endif()
 
     if(yaml-cpp_FOUND)
