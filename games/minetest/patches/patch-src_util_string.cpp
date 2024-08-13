$NetBSD: patch-src_util_string.cpp,v 1.7 2024/08/13 14:45:28 ktnb Exp $

Support non-POSIX iconv on NetBSD before 10 and SunOS.

--- src/util/string.cpp.orig	2024-08-11 15:54:55.000000000 +0000
+++ src/util/string.cpp
@@ -39,6 +39,15 @@ with this program; if not, write to the 
 	#include <windows.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 #ifndef _WIN32
 
 namespace {
