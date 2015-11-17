$NetBSD: patch-xbmc_linux_PlatformDefs.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/linux/PlatformDefs.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/linux/PlatformDefs.h
@@ -51,7 +51,7 @@
 #if defined(TARGET_DARWIN_OSX)
 #include <libkern/OSTypes.h>
 #endif
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include <stdio.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -172,7 +172,7 @@
 #define CALLBACK    __stdcall
 #define WINAPI      __stdcall
 #define WINAPIV     __cdecl
-#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD)
+#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
 #define APIENTRY    WINAPI
 #else
 #define APIENTRY
@@ -355,13 +355,15 @@ typedef int (*LPTHREAD_START_ROUTINE)(vo
 #define _O_RDONLY O_RDONLY
 #define _O_WRONLY O_WRONLY
 
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   #define stat64 stat
   #define __stat64 stat
   #define fstat64 fstat
   typedef int64_t off64_t;
   #if defined(TARGET_FREEBSD)
     #define statfs64 statfs
+  #elif defined(TARGET_NETBSD)
+    #define statfs64 statvfs
   #endif
 #else
   #define __stat64 stat64
@@ -415,8 +417,12 @@ typedef struct _SECURITY_ATTRIBUTES {
 #define FILE_CURRENT            1
 #define FILE_END                2
 
+#ifndef _S_IFREG
 #define _S_IFREG  S_IFREG
+#endif
+#ifndef _S_IFDIR
 #define _S_IFDIR  S_IFDIR
+#endif
 #define MAX_PATH PATH_MAX
 
 #define _stat stat
