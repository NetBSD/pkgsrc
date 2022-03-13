$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.10 2022/03/13 15:22:32 tnn Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.
Don't use relative @rpath in llvm-config on Darwin.

--- cmake/modules/AddLLVM.cmake.orig	2021-09-24 16:18:10.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -616,10 +616,6 @@ function(llvm_add_library name)
       set(api_name ${output_name}-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}${LLVM_VERSION_SUFFIX})
       set_target_properties(${name} PROPERTIES OUTPUT_NAME ${library_name})
       if(UNIX)
-        llvm_install_library_symlink(${api_name} ${library_name} SHARED
-          COMPONENT ${name})
-        llvm_install_library_symlink(${output_name} ${library_name} SHARED
-          COMPONENT ${name})
       endif()
     endif()
   endif()
@@ -820,11 +816,6 @@ macro(add_llvm_library name)
       endif()
 
       get_target_export_arg(${name} LLVM export_to_llvmexports ${umbrella})
-      install(TARGETS ${name}
-              ${export_to_llvmexports}
-              LIBRARY DESTINATION lib${LLVM_LIBDIR_SUFFIX} COMPONENT ${name}
-              ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX} COMPONENT ${name}
-              RUNTIME DESTINATION bin COMPONENT ${name})
 
       if (NOT LLVM_ENABLE_IDE)
         add_llvm_install_targets(install-${name}
@@ -1033,7 +1024,7 @@ function(process_llvm_pass_plugins)
 
       ## Part 1: Extension header to be included whenever we need extension
       #  processing.
-      set(LLVM_INSTALL_PACKAGE_DIR lib${LLVM_LIBDIR_SUFFIX}/cmake/llvm)
+      set(LLVM_INSTALL_PACKAGE_DIR lib/libLLVM/cmake/llvm)
       set(llvm_cmake_builddir "${LLVM_BINARY_DIR}/${LLVM_INSTALL_PACKAGE_DIR}")
       file(WRITE
           "${llvm_cmake_builddir}/LLVMConfigExtensions.cmake"
@@ -1234,7 +1225,7 @@ macro(add_llvm_tool name)
       get_target_export_arg(${name} LLVM export_to_llvmexports)
       install(TARGETS ${name}
               ${export_to_llvmexports}
-              RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR}
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT LLVM_ENABLE_IDE)
@@ -2118,7 +2109,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib/libLLVM")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(${CMAKE_SYSTEM_NAME} MATCHES "AIX" AND BUILD_SHARED_LIBS)
     # $ORIGIN is not interpreted at link time by aix ld.
