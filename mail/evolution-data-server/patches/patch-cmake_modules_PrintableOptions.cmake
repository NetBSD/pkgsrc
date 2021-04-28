$NetBSD: patch-cmake_modules_PrintableOptions.cmake,v 1.1 2021/04/28 12:21:50 cirnatdan Exp $

PrintableOptions.cmake: Correct variable name comparison
CMake 3.20.1 errors out with:

CMake Error at cmake/modules/PrintableOptions.cmake:38 (message):
   variable name cannot be empty
 Call Stack (most recent call first):
   CMakeLists.txt:152 (add_printable_variable)

Change how the parameter value is compared, to fix it.

From https://gitlab.gnome.org/GNOME/evolution-data-server/-/commit/c95a70bfeae25ba11fbe50fe759a6cdb29388e44

--- cmake/modules/PrintableOptions.cmake.orig	2019-10-11 05:42:45.000000000 +0000
+++ cmake/modules/PrintableOptions.cmake
@@ -19,36 +19,44 @@
 #    prints all the build options previously added with the above functions
 
 macro(add_printable_variable_bare _name)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "variable name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	list(APPEND _printable_options ${_name})
 endmacro()
 
 macro(add_printable_option _name _description _default_value)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "option name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	option(${_name} ${_description} ${_default_value})
 	add_printable_variable_bare(${_name})
 endmacro()
 
 macro(add_printable_variable _name _description _default_value)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "variable name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	set(${_name} ${_default_value} CACHE STRING ${_description})
 	add_printable_variable_bare(${_name})
 endmacro()
 
 macro(add_printable_variable_path _name _description _default_value)
-	if(_name STREQUAL "")
+	if("${_name}" STREQUAL "")
 		message(FATAL_ERROR "path variable name cannot be empty")
-	endif(_name STREQUAL "")
+	endif("${_name}" STREQUAL "")
 	set(${_name} ${_default_value} CACHE PATH ${_description})
 	add_printable_variable_bare(${_name})
 endmacro()
 
+macro(add_printable_variable_filepath _name _description _default_value)
+	if("${_name}" STREQUAL "")
+		message(FATAL_ERROR "filepath variable name cannot be empty")
+	endif("${_name}" STREQUAL "")
+	set(${_name} ${_default_value} CACHE FILEPATH ${_description})
+	add_printable_variable_bare(${_name})
+endmacro()
+
 function(print_build_options)
 	message(STATUS "Configure options:")
 
@@ -72,3 +80,4 @@ function(print_build_options)
 		message(STATUS ${str})
 	endforeach()
 endfunction()
+
