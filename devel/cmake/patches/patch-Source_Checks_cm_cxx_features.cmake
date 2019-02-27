$NetBSD: patch-Source_Checks_cm_cxx_features.cmake,v 1.3 2019/02/27 13:18:01 maya Exp $

Ignore warnings like ...

	ld: warning: text-based stub file /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SharedFileList.framework/Versions/A/SharedFileList.tbd and library file /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SharedFileList.framework/Versions/A/SharedFileList are out of sync. Falling back to library file for linking.

... caused by recent version of Xcode which break C++11 detection under macOS.


Handle mismatch between C++ compiler and C++ library by checking for C++17 features
(std::size, std::cend, std::cbegin)
https://gitlab.kitware.com/cmake/cmake/merge_requests/3030/diffs

--- Source/Checks/cm_cxx_features.cmake.orig	2019-02-01 13:35:27.000000000 +0000
+++ Source/Checks/cm_cxx_features.cmake
@@ -21,6 +21,7 @@ function(cm_check_cxx_feature name)
     string(REGEX REPLACE "[^\n]*warning:[^\n]*-Winvalid-command-line-argument[^\n]*" "" check_output "${check_output}")
     # Filter out warnings caused by local configuration.
     string(REGEX REPLACE "[^\n]*warning:[^\n]*directory not found for option[^\n]*" "" check_output "${check_output}")
+    string(REGEX REPLACE "[^\n]*warning:[^\n]*text-based stub file [^\n]* and library file [^\n]* are out of sync[^\n]*" "" check_output "${check_output}")
     string(REGEX REPLACE "[^\n]*warning:[^\n]*object file compiled with -mlong-branch which is no longer needed[^\n]*" "" check_output "${check_output}")
     # Filter out xcodebuild warnings.
     string(REGEX REPLACE "[^\n]* xcodebuild\\[[0-9]*:[0-9]*\\] warning: [^\n]*" "" check_output "${check_output}")
@@ -51,3 +52,18 @@ if(CMake_HAVE_CXX_MAKE_UNIQUE)
   set(CMake_HAVE_CXX_UNIQUE_PTR 1)
 endif()
 cm_check_cxx_feature(unique_ptr)
+
+cm_check_cxx_feature(size_t)
+if(CMake_HAVE_CXX_SIZE_T)
+  set(CMake_HAVE_CXX_SIZE_T 1)
+endif()
+
+cm_check_cxx_feature(cbegin)
+if(CMake_HAVE_CXX_CBEGIN)
+  set(CMake_HAVE_CXX_CBEGIN 1)
+endif()
+
+cm_check_cxx_feature(cend)
+if(CMake_HAVE_CXX_CEND)
+  set(CMake_HAVE_CXX_CEND 1)
+endif()
