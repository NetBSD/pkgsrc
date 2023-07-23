$NetBSD: patch-build__files_Modules_CompilerSettings.cmake,v 1.1 2023/07/23 21:00:18 adam Exp $

--- build_files/Modules/CompilerSettings.cmake.orig	2023-07-19 20:35:09.000000000 +0000
+++ build_files/Modules/CompilerSettings.cmake
@@ -27,7 +27,7 @@ if("${CMAKE_CXX_COMPILER_ID}" MATCHES "G
 elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
     message(STATUS "C++11 activated for Clang")
     set(CMAKE_CXX_STANDARD 11)
-    if (APPLE)
+    if (FALSE)
         set(CMAKE_EXE_LINKER_FLAGS "-lc++abi -stdlib=libc++ -rpath @loader_path/../Frameworks/")
         set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
     endif()
@@ -40,6 +40,7 @@ elseif("${CMAKE_CXX_COMPILER_ID}" MATCHE
         FIND_PACKAGE(OpenMP REQUIRED)
         SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
         SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
+        set(CMAKE_EXE_LINKER_FLAGS "-lomp")
     endif()
 elseif(MSVC)
     message(STATUS "C++11 is active by default on Microsoft Visual Studio")
