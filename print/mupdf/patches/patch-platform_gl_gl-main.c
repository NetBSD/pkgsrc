$NetBSD: patch-platform_gl_gl-main.c,v 1.1 2018/05/06 13:19:10 leot Exp $

glutSetOption() is available only on freeglut.

--- platform/gl/gl-main.c.orig	2018-04-12 13:14:06.000000000 +0000
+++ platform/gl/gl-main.c
@@ -1674,7 +1674,9 @@ int main(int argc, char **argv)
 
 	/* Init GLUT */
 
+#if defined(FREEGLUT)
 	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
+#endif
 
 	glutInitErrorFunc(on_error);
 	glutInitWarningFunc(on_warning);
