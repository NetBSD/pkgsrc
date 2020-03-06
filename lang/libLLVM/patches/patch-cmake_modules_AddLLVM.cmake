$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.9 2020/03/06 22:44:18 tnn Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.
Don't use relative @rpath in llvm-config on Darwin.

--- cmake/modules/AddLLVM.cmake.orig	2019-12-11 19:15:30.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -222,9 +222,6 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD AND
              NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD|AIX")
         # Object files are compiled with -ffunction-data-sections.
@@ -695,12 +692,6 @@ macro(add_llvm_library name)
         set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
       endif()
 
-      install(TARGETS ${name}
-              ${export_to_llvmexports}
-              LIBRARY DESTINATION lib${LLVM_LIBDIR_SUFFIX} COMPONENT ${name}
-              ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX} COMPONENT ${name}
-              RUNTIME DESTINATION bin COMPONENT ${name})
-
       if (NOT LLVM_ENABLE_IDE)
         add_llvm_install_targets(install-${name}
                                  DEPENDS ${name}
@@ -907,7 +898,7 @@ macro(add_llvm_tool name)
 
       install(TARGETS ${name}
               ${export_to_llvmexports}
-              RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR}
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT LLVM_ENABLE_IDE)
@@ -1727,7 +1718,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib/libLLVM")
     set(_install_rpath "@loader_path/../lib" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
