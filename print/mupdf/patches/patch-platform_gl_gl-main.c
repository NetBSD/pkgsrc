$NetBSD: patch-platform_gl_gl-main.c,v 1.3 2020/05/07 20:42:57 leot Exp $

glutLeaveMainLoop() is present only on freeglut, define it otherwise.

--- platform/gl/gl-main.c.orig	2020-05-05 11:29:09.000000000 +0000
+++ platform/gl/gl-main.c
@@ -26,7 +26,7 @@
 #include <direct.h> /* for getcwd */
 #endif
 
-#ifdef __APPLE__
+#ifndef FREEGLUT
 static void cleanup(void);
 void glutLeaveMainLoop(void)
 {
