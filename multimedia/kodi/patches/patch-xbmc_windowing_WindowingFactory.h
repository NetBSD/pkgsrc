$NetBSD: patch-xbmc_windowing_WindowingFactory.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/windowing/WindowingFactory.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/windowing/WindowingFactory.h
@@ -44,6 +44,12 @@
 #elif defined(TARGET_FREEBSD) && defined(HAS_GLES) && defined(HAS_EGL)
 #include "egl/WinSystemGLES.h"
 
+#elif defined(TARGET_NETBSD)  && defined(HAS_GL)   && defined(HAVE_X11)
+#include "X11/WinSystemX11GL.h"
+
+#elif defined(TARGET_NETBSD)  && defined(HAS_GLES) && defined(HAS_EGL)
+#include "egl/WinSystemGLES.h"
+
 #elif defined(TARGET_DARWIN_OSX)
 #include "osx/WinSystemOSXGL.h"
 
