$NetBSD: patch-src_egl_main_eglglobals.c,v 1.1 2016/01/27 07:39:54 wiz Exp $

atexit() is not a good idea in shared libraries.

--- src/egl/main/eglglobals.c.orig	2015-11-28 17:37:59.000000000 +0000
+++ src/egl/main/eglglobals.c
@@ -59,11 +59,16 @@ struct _egl_global _eglGlobal =
    " EGL_MESA_platform_gbm"
 };
 
+static EGLBoolean registered = EGL_FALSE;
 
-static void
+static void __attribute__((__destructor__))
 _eglAtExit(void)
 {
    EGLint i;
+
+   if (!registered)
+     return;
+
    for (i = _eglGlobal.NumAtExitCalls - 1; i >= 0; i--)
       _eglGlobal.AtExitCalls[i]();
 }
@@ -73,14 +78,9 @@ void
 _eglAddAtExitCall(void (*func)(void))
 {
    if (func) {
-      static EGLBoolean registered = EGL_FALSE;
-
       mtx_lock(_eglGlobal.Mutex);
 
-      if (!registered) {
-         atexit(_eglAtExit);
-         registered = EGL_TRUE;
-      }
+      registered = EGL_TRUE;
 
       assert(_eglGlobal.NumAtExitCalls < ARRAY_SIZE(_eglGlobal.AtExitCalls));
       _eglGlobal.AtExitCalls[_eglGlobal.NumAtExitCalls++] = func;
