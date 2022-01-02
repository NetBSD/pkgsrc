$NetBSD: patch-CMakeModules_BuildSteps_CreateDocsetDoxyfile.cmake,v 1.1 2022/01/02 19:10:03 tnn Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and contains multiple directories

--- CMakeModules/BuildSteps/CreateDocsetDoxyfile.cmake.orig	2021-12-22 13:32:19.000000000 +0000
+++ CMakeModules/BuildSteps/CreateDocsetDoxyfile.cmake
@@ -22,7 +22,7 @@
 
 function(get_kicad_doc_version RESULT_NAME)
 
-    include( ${CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
+    include( ${PROJECT_SOURCE_DIR}/CMakeModules/CreateGitVersionHeader.cmake )
     create_git_version_header(${CMAKE_SOURCE_DIR})
 
     # Now we have KICAD_VERSION, but it's got () around it
