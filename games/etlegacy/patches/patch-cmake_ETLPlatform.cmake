$NetBSD: patch-cmake_ETLPlatform.cmake,v 1.1 2019/06/23 11:20:24 maya Exp $

Have cmake figure out if -ldl should be used.
(netbsd doesn't have libdl)

--- cmake/ETLPlatform.cmake.orig	2019-01-05 19:54:35.000000000 +0000
+++ cmake/ETLPlatform.cmake
@@ -86,7 +86,7 @@ if(UNIX)
 		set(LIB_SUFFIX "_mac")
 		set(CMAKE_SHARED_MODULE_SUFFIX "")
 	else()
-		set(OS_LIBRARIES dl m rt pthread)
+		set(OS_LIBRARIES ${CMAKE_DL_LIBS} m rt pthread)
 		set(LIB_SUFFIX ".mp.")
 	endif()
 
