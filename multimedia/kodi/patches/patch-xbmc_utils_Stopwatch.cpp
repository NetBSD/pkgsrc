$NetBSD: patch-xbmc_utils_Stopwatch.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/utils/Stopwatch.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/utils/Stopwatch.cpp
@@ -21,7 +21,7 @@
 #include "Stopwatch.h"
 #if defined(TARGET_POSIX)
 #include "threads/SystemClock.h" 
-#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD)
+#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
 #include <sys/sysinfo.h>
 #endif
 #endif
