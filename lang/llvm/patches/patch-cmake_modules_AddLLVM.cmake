$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.7 2021/07/12 18:41:02 adam Exp $

On Darwin, create symbolic links to shared libraries.
On Darwin, use correct install-name for shared libraries.

--- cmake/modules/AddLLVM.cmake.orig	2020-10-07 10:10:48.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -596,7 +596,7 @@ function(llvm_add_library name)
   endif()
 
   if(ARG_SHARED AND UNIX)
-    if(NOT APPLE AND ARG_SONAME)
+    if(ARG_SONAME)
       get_target_property(output_name ${name} OUTPUT_NAME)
       if(${output_name} STREQUAL "output_name-NOTFOUND")
         set(output_name ${name})
@@ -2063,7 +2063,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
