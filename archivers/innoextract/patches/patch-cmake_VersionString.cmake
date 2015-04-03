$NetBSD: patch-cmake_VersionString.cmake,v 1.1 2015/04/03 09:40:54 wiz Exp $

Fix use of CMAKE_MODULE_PATH

--- cmake/VersionString.cmake.orig	2013-05-22 21:52:30.000000000 +0200
+++ cmake/VersionString.cmake	2013-05-22 21:53:26.000000000 +0200
@@ -47,7 +47,7 @@
 	set(mode "variable")
 	
 	set(args)
-	set(dependencies "${CMAKE_MODULE_PATH}/VersionScript.cmake")
+	set(dependencies "${CMAKE_CUSTOM_MODULE_PATH}/VersionScript.cmake")
 	
 	foreach(arg IN LISTS VERSION_SOURCES)
 		
@@ -90,7 +90,7 @@
 			"-DVERSION_SOURCES=${args}"
 			"-DGIT_DIR=${abs_git_dir}"
 			${defines}
-			-P "${CMAKE_MODULE_PATH}/VersionScript.cmake"
+			-P "${CMAKE_CUSTOM_MODULE_PATH}/VersionScript.cmake"
 		MAIN_DEPENDENCY
 			"${abs_src}"
 		DEPENDS
