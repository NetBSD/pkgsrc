$NetBSD: patch-xbmc_windowing_X11_XRandR.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/windowing/X11/XRandR.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/windowing/X11/XRandR.cpp
@@ -32,7 +32,7 @@
 #include "threads/SystemClock.h"
 #include "CompileInfo.h"
 
-#if defined(TARGET_FREEBSD)
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include <sys/types.h>
 #include <sys/wait.h>
 #endif
