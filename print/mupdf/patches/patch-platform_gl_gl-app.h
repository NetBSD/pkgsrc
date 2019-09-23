$NetBSD: patch-platform_gl_gl-app.h,v 1.3 2019/09/23 12:17:04 nia Exp $

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
+#include <GL/freeglut.h>
 
 /* UI */
 
