$NetBSD: patch-Source_Checks_cm_cxx_features.cmake,v 1.1 2018/06/11 17:33:51 tron Exp $

Ignore warnings like ...

	ld: warning: text-based stub file /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SharedFileList.framework/Versions/A/SharedFileList.tbd and library file /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SharedFileList.framework/Versions/A/SharedFileList are out of sync. Falling back to library file for linking.

... caused by recent version of Xcode which break C++11 detection under macOS.

--- Source/Checks/cm_cxx_features.cmake.orig	2018-05-31 13:39:10.000000000 +0100
+++ Source/Checks/cm_cxx_features.cmake	2018-06-11 18:24:30.000000000 +0100
@@ -21,6 +21,7 @@
     string(REGEX REPLACE "[^\n]*warning:[^\n]*-Winvalid-command-line-argument[^\n]*" "" check_output "${check_output}")
     # Filter out warnings caused by local configuration.
     string(REGEX REPLACE "[^\n]*warning:[^\n]*directory not found for option[^\n]*" "" check_output "${check_output}")
+    string(REGEX REPLACE "[^\n]*warning:[^\n]*text-based stub file [^\n]* and library file [^\n]* are out of sync[^\n]*" "" check_output "${check_output}")
     string(REGEX REPLACE "[^\n]*warning:[^\n]*object file compiled with -mlong-branch which is no longer needed[^\n]*" "" check_output "${check_output}")
     # If using the feature causes warnings, treat it as broken/unavailable.
     if(check_output MATCHES "[Ww]arning")
