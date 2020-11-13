$NetBSD: patch-src_llvm-project_llvm_cmake_modules_AddLLVM.cmake,v 1.4 2020/11/13 20:35:58 he Exp $

On Darwin, use correct install-name for shared libraries.

--- src/llvm-project/llvm/cmake/modules/AddLLVM.cmake.orig	2020-05-20 18:10:32.000000000 +0000
+++ src/llvm-project/llvm/cmake/modules/AddLLVM.cmake
@@ -2063,7 +2063,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
