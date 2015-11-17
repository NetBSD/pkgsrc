$NetBSD: patch-xbmc_storage_DetectDVDType.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/storage/DetectDVDType.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/storage/DetectDVDType.cpp
@@ -34,7 +34,7 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD)
+#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
 #include <linux/cdrom.h>
 #endif
 #endif
