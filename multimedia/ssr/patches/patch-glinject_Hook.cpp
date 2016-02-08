$NetBSD: patch-glinject_Hook.cpp,v 1.1 2016/02/08 20:43:32 markd Exp $

Linux gets environ from unistd.h

--- glinject/Hook.cpp.orig	2015-11-02 21:13:49.000000000 +0000
+++ glinject/Hook.cpp
@@ -15,6 +15,10 @@ THE SOFTWARE IS PROVIDED "AS IS" AND THE
 #include <GL/glx.h>
 #include <X11/X.h>
 
+#ifdef __NetBSD__
+extern char **environ;
+#endif
+
 typedef void (*GLXextFuncPtr)(void);
 
 void InitGLInject();
