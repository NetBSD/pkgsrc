$NetBSD: patch-Source_Checks_cm_cxx_features.cmake,v 1.2 2018/07/21 06:52:55 ryoon Exp $

Ignore warnings like ...

	ld: warning: text-based stub file /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SharedFileList.framework/Versions/A/SharedFileList.tbd and library file /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SharedFileList.framework/Versions/A/SharedFileList are out of sync. Falling back to library file for linking.

... caused by recent version of Xcode which break C++11 detection under macOS.

--- Source/Checks/cm_cxx_features.cmake.orig	2018-07-17 11:29:00.000000000 +0000
+++ Source/Checks/cm_cxx_features.cmake
@@ -21,6 +21,7 @@ function(cm_check_cxx_feature name)
     string(REGEX REPLACE "[^\n]*warning:[^\n]*-Winvalid-command-line-argument[^\n]*" "" check_output "${check_output}")
     # Filter out warnings caused by local configuration.
     string(REGEX REPLACE "[^\n]*warning:[^\n]*directory not found for option[^\n]*" "" check_output "${check_output}")
+    string(REGEX REPLACE "[^\n]*warning:[^\n]*text-based stub file [^\n]* and library file [^\n]* are out of sync[^\n]*" "" check_output "${check_output}")
     string(REGEX REPLACE "[^\n]*warning:[^\n]*object file compiled with -mlong-branch which is no longer needed[^\n]*" "" check_output "${check_output}")
     # Filter out xcodebuild warnings.
     string(REGEX REPLACE "[^\n]* xcodebuild\\[[0-9]*:[0-9]*\\] warning: [^\n]*" "" check_output "${check_output}")
