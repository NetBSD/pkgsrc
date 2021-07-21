$NetBSD: patch-cmake_CompileCheck.cmake,v 1.2 2021/07/21 12:53:20 yhardy Exp $

Resolve "Attempt at a recursive or nested TRY_COMPILE in directory"
(see also patch-CMakeLists.txt)

--- cmake/CompileCheck.cmake.orig	2021-07-14 00:04:33.000000000 +0000
+++ cmake/CompileCheck.cmake
@@ -60,7 +60,7 @@ function(check_compile RESULT FILE FLAG 
 	
 	# Check if we can compile and link a simple file with the new flags
 	try_compile(
-		check_compiler_flag ${PROJECT_BINARY_DIR} ${FILE}
+		check_compiler_flag ${CMAKE_BINARY_DIR}/CMakeTmp ${FILE}
 		CMAKE_FLAGS "-DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}"
 		            "-DCMAKE_EXE_LINKER_FLAGS:STRING=${CMAKE_EXE_LINKER_FLAGS}"
 		            "-DCMAKE_SHARED_LINKER_FLAGS:STRING=${CMAKE_SHARED_LINKER_FLAGS}"
