$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.3 2016/11/14 20:15:33 ryoon Exp $

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.

--- cmake/modules/AddLLVM.cmake.orig	2016-07-10 02:43:47.000000000 +0000
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
@@ -592,10 +594,12 @@ macro(add_llvm_loadable_module name)
         else()
           set(dlldir "lib${LLVM_LIBDIR_SUFFIX}")
         endif()
+        if (false)
         install(TARGETS ${name}
           EXPORT LLVMExports
           LIBRARY DESTINATION ${dlldir}
           ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX})
+       endif()
       endif()
       set_property(GLOBAL APPEND PROPERTY LLVM_EXPORTS ${name})
     endif()
@@ -770,7 +774,7 @@ macro(add_llvm_tool name)
     if( LLVM_BUILD_TOOLS )
       install(TARGETS ${name}
               EXPORT LLVMExports
-              RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR}
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
@@ -811,7 +815,7 @@ macro(add_llvm_utility name)
   set_target_properties(${name} PROPERTIES FOLDER "Utils")
   if( LLVM_INSTALL_UTILS AND LLVM_BUILD_UTILS )
     install (TARGETS ${name}
-      RUNTIME DESTINATION bin
+      RUNTIME DESTINATION libexec/libLLVM
       COMPONENT ${name})
     if (NOT CMAKE_CONFIGURATION_TYPES)
       add_custom_target(install-${name}
