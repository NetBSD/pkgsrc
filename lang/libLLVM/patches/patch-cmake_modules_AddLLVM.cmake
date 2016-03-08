$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.1 2016/03/08 21:06:50 tnn Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.

--- cmake/modules/AddLLVM.cmake.orig	2016-01-12 07:44:58.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -555,10 +555,12 @@ macro(add_llvm_library name)
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
@@ -699,7 +701,7 @@ macro(add_llvm_tool name)
     if( LLVM_BUILD_TOOLS )
       install(TARGETS ${name}
               EXPORT LLVMExports
-              RUNTIME DESTINATION bin
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
