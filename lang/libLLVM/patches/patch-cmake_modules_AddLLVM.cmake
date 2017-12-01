$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.5 2017/12/01 19:22:13 adam Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.

--- cmake/modules/AddLLVM.cmake.orig	2017-07-12 21:43:14.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -198,9 +198,6 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD)
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
@@ -607,10 +604,6 @@ macro(add_llvm_library name)
         set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
       endif()
 
-      install(TARGETS ${name}
-              ${export_to_llvmexports}
-              ${install_type} DESTINATION ${install_dir}
-              COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
         add_custom_target(install-${name}
@@ -648,10 +641,6 @@ macro(add_llvm_loadable_module name)
           set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
         endif()
 
-        install(TARGETS ${name}
-                ${export_to_llvmexports}
-                LIBRARY DESTINATION ${dlldir}
-                ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX})
       endif()
       set_property(GLOBAL APPEND PROPERTY LLVM_EXPORTS ${name})
     endif()
@@ -839,7 +828,7 @@ macro(add_llvm_tool name)
 
       install(TARGETS ${name}
               ${export_to_llvmexports}
-              RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR}
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
