$NetBSD: patch-cmake_Modules_DefineCompilerFlags.cmake,v 1.1 2018/02/02 10:32:25 jperkin Exp $

Leave pkgsrc to handle security features.

--- cmake/Modules/DefineCompilerFlags.cmake.orig	2015-02-11 06:57:11.000000000 +0000
+++ cmake/Modules/DefineCompilerFlags.cmake
@@ -21,6 +21,7 @@ if (UNIX AND NOT WIN32)
             set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
         endif (WITH_FPIC)
 
+        if(0)
         check_c_compiler_flag_ssp("-fstack-protector" WITH_STACK_PROTECTOR)
         if (WITH_STACK_PROTECTOR)
             set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstack-protector")
@@ -35,6 +36,7 @@ if (UNIX AND NOT WIN32)
                 endif (WITH_FORTIFY_SOURCE)
             endif()
         endif()
+        endif(0)
 
         set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
     endif (${CMAKE_C_COMPILER_ID} MATCHES "(GNU|Clang)")
