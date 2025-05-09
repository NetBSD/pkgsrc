$NetBSD: patch-cmake_QtCreatorAPI.cmake,v 1.1 2025/05/09 05:57:08 adam Exp $

Use correct install name on Darwin.
Disable application bundle.

--- cmake/QtCreatorAPI.cmake.orig	2025-03-11 12:27:32.000000000 +0000
+++ cmake/QtCreatorAPI.cmake
@@ -264,6 +264,7 @@ function(add_qtc_library name)
     VISIBILITY_INLINES_HIDDEN ON
     BUILD_RPATH "${_LIB_RPATH};${CMAKE_BUILD_RPATH}"
     INSTALL_RPATH "${_LIB_RPATH};${CMAKE_INSTALL_RPATH}"
+    INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${IDE_LIBRARY_PATH}"
     RUNTIME_OUTPUT_DIRECTORY "${_output_binary_dir}/${_DESTINATION}"
     LIBRARY_OUTPUT_DIRECTORY "${_output_binary_dir}/${IDE_LIBRARY_PATH}"
     ARCHIVE_OUTPUT_DIRECTORY "${_output_binary_dir}/${IDE_LIBRARY_ARCHIVE_PATH}"
@@ -595,6 +596,7 @@ function(add_qtc_plugin target_name)
     QTC_PLUGIN_VERSION "${_arg_VERSION}"
     BUILD_RPATH "${_PLUGIN_RPATH};${CMAKE_BUILD_RPATH}"
     INSTALL_RPATH "${_PLUGIN_RPATH};${CMAKE_INSTALL_RPATH}"
+    INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${plugin_dir}"
     LIBRARY_OUTPUT_DIRECTORY "${_output_binary_dir}/${plugin_dir}"
     ARCHIVE_OUTPUT_DIRECTORY "${_output_binary_dir}/${plugin_dir}"
     RUNTIME_OUTPUT_DIRECTORY "${_output_binary_dir}/${plugin_dir}"
@@ -737,7 +739,7 @@ function(add_qtc_executable name)
   endif()
 
   set(_EXECUTABLE_PATH "${_DESTINATION}")
-  if (APPLE)
+  if (FALSE)
     # path of executable might be inside app bundle instead of DESTINATION directly
     cmake_parse_arguments(_prop "" "MACOSX_BUNDLE;OUTPUT_NAME" "" "${_arg_PROPERTIES}")
     if (_prop_MACOSX_BUNDLE)
@@ -822,7 +824,7 @@ function(add_qtc_executable name)
     # when installing app bundles, which copies things that it should not
     # like static libraries, executables with SKIP_INSTALL, clang resources
     # and dSYM directories
-    if (APPLE AND _EXECUTABLE_FILE_PATH AND _BUNDLE_INFO_PLIST)
+    if (FALSE AND _EXECUTABLE_FILE_PATH AND _BUNDLE_INFO_PLIST)
       install(
         PROGRAMS "${_output_binary_dir}/${_EXECUTABLE_FILE_PATH}"
         DESTINATION "${_EXECUTABLE_PATH}"
