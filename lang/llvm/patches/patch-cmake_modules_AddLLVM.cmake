$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.6 2020/04/18 07:50:18 adam Exp $

Don't use non-portable -z discard-unused on SunOS.
On Darwin, create symbolic links to shared libraries.
On Darwin, use correct install-name for shared libraries.

--- cmake/modules/AddLLVM.cmake.orig	2020-03-19 09:19:04.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -233,9 +233,6 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD AND
              NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD|AIX")
         # Object files are compiled with -ffunction-data-sections.
@@ -562,7 +559,7 @@ function(llvm_add_library name)
   endif()
 
   if(ARG_SHARED AND UNIX)
-    if(NOT APPLE AND ARG_SONAME)
+    if(ARG_SONAME)
       get_target_property(output_name ${name} OUTPUT_NAME)
       if(${output_name} STREQUAL "output_name-NOTFOUND")
         set(output_name ${name})
@@ -1887,7 +1884,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
