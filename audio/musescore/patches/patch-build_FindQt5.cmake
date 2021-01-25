$NetBSD: patch-build_FindQt5.cmake,v 1.1 2021/01/25 02:42:44 gutteridge Exp $

Upstream fix: don't disable Qt 5.15 for 3.x 
https://github.com/musescore/MuseScore/commit/28aa7ba50a7d26b7c55728a86e5a6ccff7bf9fbb

--- build/FindQt5.cmake.orig	2021-01-15 12:36:02.000000000 +0000
+++ build/FindQt5.cmake
@@ -36,14 +36,6 @@ if (WIN32)
       )
 endif(WIN32)
 
-# For Windows, because of these lines, for some unknown reason, the build of the .msi package fails.
-if(NOT ${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows")
-    find_package(Qt5Core 5.15.0 QUIET)
-    if (Qt5Core_FOUND)
-        message(FATAL_ERROR "MuseScore 3 does not support Qt 5.15: 5.15.0 shows empty palettes panel, 5.15.1 and later crash when opening pre-3.6 scores due to QTBUG-77337")
-    endif()
-endif()
-
 find_package(Qt5Core ${QT_MIN_VERSION} REQUIRED)
 
 foreach(_component ${_components})
