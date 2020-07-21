$NetBSD: patch-src_appl_jiv.c,v 1.1 2020/07/21 07:31:28 adam Exp $

Support GLUT/glut.h.

--- src/appl/jiv.c.orig	2020-07-21 07:10:06.000000000 +0000
+++ src/appl/jiv.c
@@ -69,6 +69,8 @@
 #include <inttypes.h>
 #if defined(JAS_HAVE_GL_GLUT_H)
 #include <GL/glut.h>
+#elif defined(JAS_HAVE_GLUT_GLUT_H)
+#include <GLUT/glut.h>
 #else
 #include <glut.h>
 #endif
