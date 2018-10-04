$NetBSD: patch-platform_gl_gl-app.h,v 1.2 2018/10/04 19:02:33 leot Exp $

- Do not force freeglut GLUT implementation to every non-APPLE platforms.
- Adjust the glut.h include.

--- platform/gl/gl-app.h.orig	2018-09-25 12:39:17.000000000 +0000
+++ platform/gl/gl-app.h
@@ -7,11 +7,7 @@ void win_install(void);
 #include "mupdf/ucdn.h"
 #include "mupdf/pdf.h" /* for pdf specifics and forms */
 
-#ifndef __APPLE__
-#include <GL/freeglut.h>
-#else
-#include <GLUT/glut.h>
-#endif
+#include <GL/glut.h>
 
 /* UI */
 
