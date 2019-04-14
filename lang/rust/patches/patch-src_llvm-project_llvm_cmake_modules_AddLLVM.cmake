$NetBSD: patch-src_llvm-project_llvm_cmake_modules_AddLLVM.cmake,v 1.1 2019/04/14 12:42:03 he Exp $

"-z discard-unused" is only supported by Oracle Solaris ld.
On Darwin, use correct install-name for shared libraries.

--- src/llvm-project/llvm/cmake/modules/AddLLVM.cmake.orig	2018-08-01 16:32:37.000000000 +0000
+++ src/llvm-project/llvm/cmake/modules/AddLLVM.cmake
@@ -219,8 +219,6 @@ function(add_link_opts target_name)
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
       elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD AND NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
@@ -1602,7 +1600,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
     set(_install_rpath "@loader_path/../lib" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
