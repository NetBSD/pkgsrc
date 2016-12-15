$NetBSD: patch-glinject_Hook.cpp,v 1.2 2016/12/15 22:40:10 wiedi Exp $

Linux gets environ from unistd.h

--- glinject/Hook.cpp.orig	2015-11-02 21:13:49.000000000 +0000
+++ glinject/Hook.cpp
@@ -15,6 +15,10 @@ THE SOFTWARE IS PROVIDED "AS IS" AND THE
 #include <GL/glx.h>
 #include <X11/X.h>
 
+#if defined(__NetBSD__) || defined(__sun)
+extern char **environ;
+#endif
+
 typedef void (*GLXextFuncPtr)(void);
 
 void InitGLInject();
