$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.4 2017/03/17 22:38:18 adam Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.

--- cmake/modules/AddLLVM.cmake.orig	2017-01-17 21:47:58.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -182,9 +182,6 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD)
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
@@ -591,10 +588,6 @@ macro(add_llvm_library name)
         set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
       endif()
 
-      install(TARGETS ${name}
-              ${export_to_llvmexports}
-              ${install_type} DESTINATION ${install_dir}
-              COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
         add_custom_target(install-${name}
@@ -632,10 +625,6 @@ macro(add_llvm_loadable_module name)
           set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
         endif()
 
-        install(TARGETS ${name}
-                ${export_to_llvmexports}
-                LIBRARY DESTINATION ${dlldir}
-                ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX})
       endif()
       set_property(GLOBAL APPEND PROPERTY LLVM_EXPORTS ${name})
     endif()
@@ -823,7 +812,7 @@ macro(add_llvm_tool name)
 
       install(TARGETS ${name}
               ${export_to_llvmexports}
-              RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR}
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
@@ -864,7 +853,7 @@ macro(add_llvm_utility name)
   set_target_properties(${name} PROPERTIES FOLDER "Utils")
   if( LLVM_INSTALL_UTILS AND LLVM_BUILD_UTILS )
     install (TARGETS ${name}
-      RUNTIME DESTINATION bin
+      RUNTIME DESTINATION libexec/libLLVM
       COMPONENT ${name})
     if (NOT CMAKE_CONFIGURATION_TYPES)
       add_custom_target(install-${name}
