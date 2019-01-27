$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.8 2019/01/27 00:07:32 tnn Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.
Don't use relative @rpath in llvm-config on Darwin.

--- cmake/modules/AddLLVM.cmake.orig	2018-08-01 07:51:55.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -218,9 +218,6 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD AND NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
@@ -654,11 +651,6 @@ macro(add_llvm_library name)
         set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
       endif()
 
-      install(TARGETS ${name}
-              ${export_to_llvmexports}
-              ${install_type} DESTINATION ${install_dir}
-              COMPONENT ${name})
-
       if (NOT CMAKE_CONFIGURATION_TYPES)
         add_llvm_install_targets(install-${name}
                                  DEPENDS ${name}
@@ -693,10 +685,6 @@ macro(add_llvm_loadable_module name)
           set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
         endif()
 
-        install(TARGETS ${name}
-                ${export_to_llvmexports}
-                LIBRARY DESTINATION ${dlldir}
-                ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX})
       endif()
       set_property(GLOBAL APPEND PROPERTY LLVM_EXPORTS ${name})
     endif()
@@ -887,7 +875,7 @@ macro(add_llvm_tool name)
 
       install(TARGETS ${name}
               ${export_to_llvmexports}
-              RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR}
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
@@ -1632,7 +1620,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib/libLLVM")
     set(_install_rpath "@loader_path/../lib" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
