$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.8 2021/11/23 20:55:44 wiz Exp $

On Darwin, create symbolic links to shared libraries.
On Darwin, use correct install-name for shared libraries.

--- cmake/modules/AddLLVM.cmake.orig	2021-09-24 16:18:10.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -607,7 +607,7 @@ function(llvm_add_library name)
   endif()
 
   if(ARG_SHARED)
-    if(NOT APPLE AND ARG_SONAME)
+    if(ARG_SONAME)
       get_target_property(output_name ${name} OUTPUT_NAME)
       if(${output_name} STREQUAL "output_name-NOTFOUND")
         set(output_name ${name})
@@ -2118,7 +2118,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(${CMAKE_SYSTEM_NAME} MATCHES "AIX" AND BUILD_SHARED_LIBS)
     # $ORIGIN is not interpreted at link time by aix ld.
