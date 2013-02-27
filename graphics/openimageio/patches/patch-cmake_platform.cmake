$NetBSD: patch-cmake_platform.cmake,v 1.2 2013/02/27 15:19:02 ryoon Exp $

* Add NetBSD support

--- cmake/platform.cmake.orig	2013-02-21 17:10:46.000000000 +0000
+++ cmake/platform.cmake
@@ -30,6 +30,16 @@ if (UNIX)
                 set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=i586")
             endif()
         endif()
+    elseif (${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD")
+	set (platform "NetBSD")
+	set (CXXFLAGS "${CXXFLAGS} -DNETBSD")
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
