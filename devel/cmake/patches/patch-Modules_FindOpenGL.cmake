$NetBSD: patch-Modules_FindOpenGL.cmake,v 1.1 2022/10/09 12:06:05 rhialto Exp $

Despite complicated wording in the module, pkgsrc's MesaLib has no libOpenGL
but does have (conditionally) libGL. Possibly all conditions and dependencies
on (Open)GL should even be removed here.

https://github.com/wxWidgets/wxWidgets/issues/22841
https://gitlab.kitware.com/cmake/cmake/-/issues/24019

--- Modules/FindOpenGL.cmake.orig	2022-08-17 16:54:57.000000000 +0000
+++ Modules/FindOpenGL.cmake
@@ -520,7 +520,9 @@ if(OPENGL_FOUND)
   # Note we test for OpenGL::OpenGL as a target.  When this module is updated to
   # support GLES, we would additionally want to check for the hypothetical GLES
   # target and enable EGL if either ::GLES or ::OpenGL is created.
-  if(TARGET OpenGL::OpenGL AND OpenGL_EGL_FOUND AND NOT TARGET OpenGL::EGL)
+  # Pkgsrc note: despite complicated wording above, pkgsrc's MesaLib
+  # has no libOpenGL but does have (conditionally) libGL.
+  if(TARGET OpenGL::GL AND OpenGL_EGL_FOUND AND NOT TARGET OpenGL::EGL)
     if(IS_ABSOLUTE "${OPENGL_egl_LIBRARY}")
       add_library(OpenGL::EGL UNKNOWN IMPORTED)
       set_target_properties(OpenGL::EGL PROPERTIES IMPORTED_LOCATION
@@ -531,7 +533,7 @@ if(OPENGL_FOUND)
                             "${OPENGL_egl_LIBRARY}")
     endif()
     set_target_properties(OpenGL::EGL PROPERTIES INTERFACE_LINK_LIBRARIES
-                          OpenGL::OpenGL)
+                          OpenGL::GL)
     # Note that EGL's include directory is different from OpenGL/GLX's!
     set_target_properties(OpenGL::EGL PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                           "${OPENGL_EGL_INCLUDE_DIR}")
