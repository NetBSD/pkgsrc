$NetBSD: patch-es-core_src_utils_FileSystemUtil.cpp,v 1.2 2025/08/22 05:31:50 adam Exp $

stat64 is non-portable

--- es-core/src/utils/FileSystemUtil.cpp.orig	2023-04-13 14:23:07.000000000 +0000
+++ es-core/src/utils/FileSystemUtil.cpp
@@ -21,6 +21,10 @@
 #else // _WIN32
 #include <dirent.h>
 #include <unistd.h>
+#ifndef __linux__
+#define stat64 stat
+#define lstat64 lstat
+#endif
 #endif // _WIN32
 
 //////////////////////////////////////////////////////////////////////////
