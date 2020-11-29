$NetBSD: patch-cmake_FindPortaudio.cmake,v 1.1 2020/11/29 23:14:21 dbj Exp $

Remove special case Darwin search for portaudio that was
seting the wrong path to the libraries

--- cmake/FindPortaudio.cmake.orig	2019-11-11 21:00:04.000000000 +0000
+++ cmake/FindPortaudio.cmake
@@ -27,13 +27,9 @@ else (PORTAUDIO_LIBRARIES AND PORTAUDIO_
     set(PORTAUDIO_INCLUDE_DIRS
       ${PORTAUDIO2_INCLUDE_DIRS}
     )
-    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
-      set(PORTAUDIO_LIBRARIES "${PORTAUDIO2_LIBRARY_DIRS}/lib${PORTAUDIO2_LIBRARIES}.dylib")
-    else (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
-      set(PORTAUDIO_LIBRARIES
-        ${PORTAUDIO2_LIBRARIES}
-      )
-    endif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
+    set(PORTAUDIO_LIBRARIES
+      ${PORTAUDIO2_LIBRARIES}
+    )
     set(PORTAUDIO_VERSION
       19
     )
