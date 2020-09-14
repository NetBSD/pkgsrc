$NetBSD: patch-build_cmake_modules_JasOpenGL.cmake,v 1.1 2020/09/14 17:47:14 adam Exp $

Support GLUT/glut.h.

--- build/cmake/modules/JasOpenGL.cmake.orig	2020-09-14 17:26:49.000000000 +0000
+++ build/cmake/modules/JasOpenGL.cmake
@@ -19,9 +19,10 @@ if (JAS_ENABLE_OPENGL AND OPENGL_FOUND)
 		message("GLUT include directory: ${GLUT_INCLUDE_DIR}")
 		message("GLUT libraries: ${GLUT_LIBRARIES}")
 		set(CMAKE_REQUIRED_INCLUDES ${GLUT_INCLUDE_DIR})
+		check_include_files(GLUT/glut.h JAS_HAVE_GLUT_GLUT_H)
 		check_include_files(GL/glut.h JAS_HAVE_GL_GLUT_H)
 		check_include_files(glut.h JAS_HAVE_GLUT_H)
-		if (JAS_HAVE_GL_GLUT_H OR JAS_HAVE_GLUT_H)
+		if (JAS_HAVE_GLUT_GLUT_H OR JAS_HAVE_GL_GLUT_H OR JAS_HAVE_GLUT_H)
 			set(JAS_HAVE_OPENGL 1)
 			include_directories(${GLUT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
 		else()
