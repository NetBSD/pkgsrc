$NetBSD: patch-cmake_CompileCheck.cmake,v 1.1 2016/09/02 16:46:04 wiz Exp $

Resolve "Attempt at a recursive or nested TRY_COMPILE in directory"
(see also patch-CMakeLists.txt)

--- cmake/CompileCheck.cmake.orig	2013-07-15 20:31:38.000000000 +0200
+++ cmake/CompileCheck.cmake	2013-07-15 20:32:36.000000000 +0200
@@ -52,7 +52,7 @@
 	
 	# Check if we can compile and link a simple file with the new flags
 	try_compile(
-		check_compiler_flag ${CMAKE_BINARY_DIR} ${FILE}
+		check_compiler_flag ${CMAKE_BINARY_DIR}/CMakeTmp ${FILE}
 		CMAKE_FLAGS "-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}"
 		            "-DCMAKE_EXE_LINKER_FLAGS=${CMAKE_EXE_LINKER_FLAGS}"
 		            "-DCMAKE_SHARED_LINKER_FLAGS=${CMAKE_SHARED_LINKER_FLAGS}"
