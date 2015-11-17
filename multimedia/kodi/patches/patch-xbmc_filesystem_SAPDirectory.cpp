$NetBSD: patch-xbmc_filesystem_SAPDirectory.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/filesystem/SAPDirectory.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/filesystem/SAPDirectory.cpp
@@ -34,7 +34,7 @@
 #if defined(TARGET_DARWIN)
 #include "osx/OSXGNUReplacements.h" // strnlen
 #endif
-#ifdef TARGET_FREEBSD
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include "freebsd/FreeBSDGNUReplacements.h"
 #endif
 
