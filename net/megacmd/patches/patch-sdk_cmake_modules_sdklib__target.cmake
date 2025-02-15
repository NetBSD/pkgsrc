$NetBSD: patch-sdk_cmake_modules_sdklib__target.cmake,v 1.1 2025/02/15 07:40:13 wiz Exp $

* On gcc-10 std::filesystem is in stdc++

--- sdk/cmake/modules/sdklib_target.cmake.orig	2025-02-07 10:00:44.872621812 +0100
+++ sdk/cmake/modules/sdklib_target.cmake
@@ -358,7 +358,7 @@ endif()
 load_sdklib_libraries()
 
 # System libraries
-if((NOT (WIN32 OR APPLE OR ANDROID)) AND CMAKE_CXX_STANDARD LESS_EQUAL 17)
+if((NOT (WIN32 OR APPLE OR ANDROID OR UNIX)) AND CMAKE_CXX_STANDARD LESS_EQUAL 17)
     # Needed for std::experimental::filesystem
     # Needed for c++17 and std::filesystem for some compilers. Not needed starting in gcc9, but harmless.
     target_link_libraries(SDKlib PRIVATE stdc++fs)
