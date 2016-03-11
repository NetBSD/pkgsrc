$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.2 2016/03/11 06:50:42 tnn Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.

--- cmake/modules/AddLLVM.cmake.orig	2016-02-12 17:52:29.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -174,9 +174,9 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
+#      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
+#        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
+#                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD)
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
@@ -558,10 +558,12 @@ macro(add_llvm_library name)
         set(install_type ARCHIVE)
       endif()
 
+      if (false)
       install(TARGETS ${name}
             EXPORT LLVMExports
             ${install_type} DESTINATION ${install_dir}
             COMPONENT ${name})
+      endif()
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
         add_custom_target(install-${name}
@@ -702,7 +704,7 @@ macro(add_llvm_tool name)
     if( LLVM_BUILD_TOOLS )
       install(TARGETS ${name}
               EXPORT LLVMExports
-              RUNTIME DESTINATION bin
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
