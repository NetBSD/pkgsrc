$NetBSD: patch-src_symbols.cmake,v 1.1 2015/02/13 17:07:52 jperkin Exp $

Don't use GNU ld arguments on SunOS.

--- src/symbols.cmake.orig	2013-04-11 17:23:05.000000000 +0000
+++ src/symbols.cmake
@@ -21,7 +21,7 @@ if (APPLE)
 	set(LINK_FLAGS
 		"${LINK_FLAGS} -Wl,-exported_symbols_list,'${_symbols_list}'")
 
-elseif (CMAKE_C_COMPILER_ID STREQUAL GNU)
+elseif (CMAKE_C_COMPILER_ID STREQUAL GNU AND NOT CPACK_SYSTEM_NAME STREQUAL SunOS)
 	# Create a version script for GNU ld.
 	set(_symbols "{ global: ${OPENCC_SYMBOLS}; local: *; };")
 	set(_version_script "${CMAKE_CURRENT_BINARY_DIR}/version.script")
@@ -37,4 +37,4 @@ set_target_properties(
 	PROPERTIES
 		LINK_FLAGS
 			"${LINK_FLAGS}"
-)
\ No newline at end of file
+)
