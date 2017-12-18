$NetBSD: patch-platform_gl_gl-app.h,v 1.1 2017/12/18 15:06:34 leot Exp $

- Do not force freeglut GLUT implementation to every non-APPLE platforms.
- Adjust the glut.h include.

--- platform/gl/gl-app.h.orig	2017-11-23 11:42:45.000000000 +0000
+++ platform/gl/gl-app.h
@@ -7,11 +7,7 @@ int win_open_file(char *buf, int len);
 #include "mupdf/fitz.h"
 #include "mupdf/ucdn.h"
 
-#ifndef __APPLE__
-#include <GL/freeglut.h>
-#else
-#include <GLUT/glut.h>
-#endif
+#include <GL/glut.h>
 
 extern fz_context *ctx;
 
