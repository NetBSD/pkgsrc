$NetBSD: patch-xbmc_cores_DllLoader_exports_util_EmuFileWrapper.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/cores/DllLoader/exports/util/EmuFileWrapper.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/cores/DllLoader/exports/util/EmuFileWrapper.h
@@ -27,7 +27,7 @@
 #include "system.h"
 #include "threads/CriticalSection.h"
 
-#if defined(TARGET_POSIX) && !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_ANDROID) && !defined(__UCLIBC__)
+#if defined(TARGET_POSIX) && !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD) && !defined(TARGET_ANDROID) && !defined(__UCLIBC__)
 #define _file _fileno
 #elif defined(__UCLIBC__)
 #define _file __filedes
