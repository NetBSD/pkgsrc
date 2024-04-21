$NetBSD: patch-cmake_cotire.cmake,v 1.2 2024/04/21 17:28:32 adam Exp $

Disable precompiled headers. Makes GCC segfault on NetBSD-7.0-i386.

--- cmake/cotire.cmake.orig	2024-02-18 18:18:26.000000000 +0000
+++ cmake/cotire.cmake
@@ -3557,6 +3557,9 @@ function (cotire_setup_clean_all_target)
 endfunction()
 
 function (cotire)
+if (true)
+# nothing, disable use of precompiled headers
+else()
 	set(_options "")
 	set(_oneValueArgs "")
 	set(_multiValueArgs LANGUAGES CONFIGURATIONS)
@@ -3574,6 +3577,7 @@ function (cotire)
 			cotire_target_link_libraries(${_target})
 		endif()
 	endforeach()
+endif()
 endfunction()
 
 if (CMAKE_SCRIPT_MODE_FILE)
