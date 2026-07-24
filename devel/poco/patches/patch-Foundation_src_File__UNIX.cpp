$NetBSD: patch-Foundation_src_File__UNIX.cpp,v 1.1 2026/07/24 12:15:52 adam Exp $

Support NetBSD.

--- Foundation/src/File_UNIX.cpp.orig	2026-07-24 10:06:50.947683933 +0000
+++ Foundation/src/File_UNIX.cpp
@@ -38,7 +38,7 @@
 #include <utime.h>
 #include <cstring>
 
-#if (POCO_OS == POCO_OS_SOLARIS) || (POCO_OS == POCO_OS_QNX)
+#if (POCO_OS == POCO_OS_SOLARIS) || (POCO_OS == POCO_OS_QNX) || (POCO_OS == POCO_OS_NET_BSD)
 #define STATFSFN ::statvfs
 #define STATFSSTRUCT statvfs
 #else
