$NetBSD: patch-lib_jxl__threads.cmake,v 1.1 2025/02/04 11:22:48 wiz Exp $

All linkers do not support --version-script, so test for it

--- lib/jxl_threads.cmake.orig	2024-01-05 17:14:55.908788800 +0000
+++ lib/jxl_threads.cmake
@@ -46,8 +46,10 @@ if(APPLE)
 elseif(WIN32)
 # Nothing needed here, we use __declspec(dllexport) (jxl_threads_export.h)
 else()
+  if(LINKER_VERSION_SCRIPT)
   set_property(TARGET jxl_threads APPEND_STRING PROPERTY
       LINK_FLAGS " -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
+  endif() # LINKER_VERSION_SCRIPT
 endif()  # APPLE
 
 # Compile the shared library such that the JXL_THREADS_EXPORT symbols are
