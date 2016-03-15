$NetBSD: patch-cmake_cotire.cmake,v 1.1 2016/03/15 00:24:29 tnn Exp $

Disable precompiled headers. Makes GCC segfault on NetBSD-7.0-i386.

--- cmake/cotire.cmake.orig	2015-01-30 16:14:22.000000000 +0000
+++ cmake/cotire.cmake
@@ -2956,6 +2956,9 @@ function (cotire_setup_clean_all_target)
 endfunction()
 
 function (cotire)
+if (true)
+# nothing, disable use of precompiled headers
+else()
 	set(_options "")
 	set(_oneValueArgs SOURCE_DIR BINARY_DIR)
 	set(_multiValueArgs LANGUAGES CONFIGURATIONS)
@@ -2980,6 +2983,7 @@ function (cotire)
 			cotire_target_link_libraries(${_target})
 		endif()
 	endforeach()
+endif()
 endfunction()
 
 if (CMAKE_SCRIPT_MODE_FILE)
