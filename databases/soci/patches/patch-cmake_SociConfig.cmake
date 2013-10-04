$NetBSD: patch-cmake_SociConfig.cmake,v 1.1 2013/10/04 18:32:07 joerg Exp $

--- cmake/SociConfig.cmake.orig	2013-08-21 22:40:11.000000000 +0000
+++ cmake/SociConfig.cmake
@@ -28,19 +28,11 @@ if (MSVC)
   
 else()
 
-  set(SOCI_GCC_CLANG_COMMON_FLAGS
-	"-pedantic -ansi -Wall -Wpointer-arith -Wcast-align -Wcast-qual -Wfloat-equal -Wredundant-decls -Wno-long-long")
+  set(SOCI_GCC_CLANG_COMMON_FLAGS "-Wall -Wpointer-arith -Wcast-align -Wcast-qual -Wfloat-equal -Wredundant-decls -Wno-long-long")
 
   if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
         
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC ${SOCI_GCC_CLANG_COMMON_FLAGS}")
-    if (CMAKE_COMPILER_IS_GNUCXX)
-        if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
-            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++98")
-        else()
-            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
-        endif()
-    endif()
 
   elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" OR "${CMAKE_CXX_COMPILER}" MATCHES "clang")
 
