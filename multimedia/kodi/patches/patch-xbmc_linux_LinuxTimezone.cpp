$NetBSD: patch-xbmc_linux_LinuxTimezone.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/linux/LinuxTimezone.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/linux/LinuxTimezone.cpp
@@ -29,7 +29,7 @@
 #if defined(TARGET_DARWIN)
 #include "osx/OSXGNUReplacements.h"
 #endif
-#ifdef TARGET_FREEBSD
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include "freebsd/FreeBSDGNUReplacements.h"
 #endif
 
