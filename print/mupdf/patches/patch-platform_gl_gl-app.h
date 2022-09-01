$NetBSD: patch-platform_gl_gl-app.h,v 1.5 2022/09/01 13:56:53 nia Exp $

- Use freeglut everywhere.

--- platform/gl/gl-app.h.orig	2020-05-05 11:29:09.000000000 +0000
+++ platform/gl/gl-app.h
@@ -7,11 +7,7 @@ void win_install(void);
 #include "mupdf/ucdn.h"
 #include "mupdf/pdf.h" /* for pdf specifics and forms */
 
-#ifndef __APPLE__
 #include <GL/freeglut.h>
-#else
-#include <GLUT/glut.h>
-#endif
 
 /* UI */
 
