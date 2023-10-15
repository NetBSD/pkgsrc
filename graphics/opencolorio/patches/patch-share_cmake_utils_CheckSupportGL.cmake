$NetBSD: patch-share_cmake_utils_CheckSupportGL.cmake,v 1.1 2023/10/15 19:45:33 ryoon Exp $

* pkgsrc does not provide libOpenGL.so.

--- share/cmake/utils/CheckSupportGL.cmake.orig	2023-01-06 02:05:59.000000000 +0000
+++ share/cmake/utils/CheckSupportGL.cmake
@@ -76,14 +76,6 @@ if((OCIO_BUILD_TESTS AND OCIO_BUILD_GPU_
     if(NOT OCIO_GL_ENABLED)
         message(WARNING "GPU rendering disabled")
     else()
-        # OpenGL_egl_Library is defined iff GLVND is supported (CMake 10+).
-        if(OPENGL_egl_LIBRARY)
-            message(STATUS "GLVND supported")
-            set(OCIO_USE_GLVND ON)
-        else()
-            message(STATUS "GLVND not supported; legacy OpenGL libraries used")
-        endif()
-
         if(OCIO_USE_HEADLESS)
             if(CMAKE_SYSTEM_NAME STREQUAL Linux)
                 if(NOT OCIO_USE_GLVND)
