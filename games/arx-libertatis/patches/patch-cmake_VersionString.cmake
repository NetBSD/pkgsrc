$NetBSD: patch-cmake_VersionString.cmake,v 1.1 2016/09/02 16:46:04 wiz Exp $

Fix use of CMAKE_MODULE_PATH (see also patch-CMakeLists.txt)

and

commit afca1491d7114066c016149b421bae4c797663a2
Author: Daniel Scharrer <daniel@constexpr.org>
Date:   Tue Feb 23 07:08:48 2016 +0100

    VersionString.cmake: Guard against defined variables
    
    Previously this would fail under CMake older than 3.1 if "file" or
    "variable" were variables.
    
    For CMake 3.1+ this was fixed in commit 60e43c.

--- cmake/VersionString.cmake.orig	2013-10-17 17:25:04.000000000 +0000
+++ cmake/VersionString.cmake
@@ -26,19 +26,22 @@
 # The version file is regenerated whenever VERSION_FILE or the current commit changes.
 function(version_file SRC DST VERSION_SOURCES GIT_DIR)
 	
-	set(mode "variable")
+	set(MODE_VARIABLE 0)
+	set(MODE_FILE 1)
+
+	set(mode ${MODE_VARIABLE})
 	
 	set(args)
-	set(dependencies "${CMAKE_MODULE_PATH}/VersionScript.cmake")
+	set(dependencies "${CMAKE_CUSTOM_MODULE_PATH}/VersionScript.cmake")
 	
 	foreach(arg IN LISTS VERSION_SOURCES)
 		
-		if(mode STREQUAL "variable")
-			set(mode "file")
+		if(mode EQUAL MODE_VARIABLE)
+			set(mode ${MODE_FILE})
 		else()
 			get_filename_component(arg "${arg}" ABSOLUTE)
 			list(APPEND dependencies ${arg})
-			set(mode "variable")
+			set(mode ${MODE_VARIABLE})
 		endif()
 		
 		list(APPEND args ${arg})
@@ -72,7 +75,7 @@ function(version_file SRC DST VERSION_SO
 			"-DVERSION_SOURCES=${args}"
 			"-DGIT_DIR=${abs_git_dir}"
 			${defines}
-			-P "${CMAKE_MODULE_PATH}/VersionScript.cmake"
+			-P "${CMAKE_CUSTOM_MODULE_PATH}/VersionScript.cmake"
 		MAIN_DEPENDENCY
 			"${abs_src}"
 		DEPENDS
