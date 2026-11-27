$NetBSD: patch-build__files_cmake_platform_platform__unix.cmake,v 1.1 2026/11/27 13:46:27 adam Exp $

--- build_files/cmake/platform/platform_unix.cmake.orig	2026-08-26 13:58:36.754398833 +0000
+++ build_files/cmake/platform/platform_unix.cmake
@@ -158,7 +158,7 @@ if(WITH_VULKAN_BACKEND)
     # Use system libs
     find_package(PkgConfig)
     pkg_check_modules(VULKAN REQUIRED vulkan)
-    pkg_check_modules(SHADERC REQUIRED shaderc)
+    pkg_check_modules(SHADERC REQUIRED shaderc_static)
   endif()
 endif()
 add_bundled_libraries(vulkan/lib)
