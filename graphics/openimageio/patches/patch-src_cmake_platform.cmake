$NetBSD: patch-src_cmake_platform.cmake,v 1.1 2014/04/07 12:15:55 ryoon Exp $

--- src/cmake/platform.cmake.orig	2014-04-03 06:08:57.000000000 +0000
+++ src/cmake/platform.cmake
@@ -28,6 +28,16 @@ if (UNIX)
             # with arch of i586 or higher
             set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=i586")
         endif()
+    elseif (${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD")
+        set (platform "NetBSD")
+        set (CXXFLAGS "${CXXFLAGS} -DNETBSD")
+        if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "i386")
+            if (NOT USE_TBB)
+                # to use gcc atomics we need cpu instructions only available
+                # with arch of i586 or higher
+                set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=i586")
+            endif()
+        endif()
     else ()
         string (TOLOWER ${CMAKE_SYSTEM_NAME} platform)
     endif ()
