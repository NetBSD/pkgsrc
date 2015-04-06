$NetBSD: patch-src_glut_glx_glutint.h,v 1.1 2015/04/06 07:07:43 tnn Exp $

Fix Solaris ifdef.

--- src/glut/glx/glutint.h.orig	2010-12-14 21:46:56.000000000 +0000
+++ src/glut/glx/glutint.h
@@ -92,7 +92,7 @@ extern int sys$gettim(struct timeval6 *)
 #define IS_AT_OR_AFTER(t1, t2) ((t2).val >= (t1).val)
 
 #else
-#if defined(SVR4) && !defined(sun)  /* Sun claims SVR4, but
+#if defined(SVR4) && !defined(__sun)  /* Sun claims SVR4, but
                                        wants 2 args. */
 #define GETTIMEOFDAY(_x) gettimeofday(_x)
 #else
