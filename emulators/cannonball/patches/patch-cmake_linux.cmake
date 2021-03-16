$NetBSD: patch-cmake_linux.cmake,v 1.1 2021/03/16 23:51:49 fox Exp $

Adds support for building in Linux / BSD.

Will be removed once upstream makes a release with
https://github.com/djyt/cannonball/commit/a9c71cbf229b9f808ae172a09d12a773fc869209

--- cmake/linux.cmake.orig	2021-03-16 09:31:59.333255192 +0000
+++ cmake/linux.cmake
@@ -0,0 +1,11 @@
+# -----------------------------------------------------------------------------
+# CannonBall Linux Setup
+# -----------------------------------------------------------------------------
+
+# Use OpenGL for rendering.
+find_package(OpenGL REQUIRED)
+
+# Platform Specific Libraries
+set(platform_link_libs
+    ${OPENGL_LIBRARIES}
+)
\ No newline at end of file
