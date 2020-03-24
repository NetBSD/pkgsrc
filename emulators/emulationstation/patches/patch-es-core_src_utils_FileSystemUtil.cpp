$NetBSD: patch-es-core_src_utils_FileSystemUtil.cpp,v 1.1 2020/03/24 15:52:38 nia Exp $

stat64 is non-portable

--- es-core/src/utils/FileSystemUtil.cpp.orig	2019-12-29 21:18:29.000000000 +0000
+++ es-core/src/utils/FileSystemUtil.cpp
@@ -19,6 +19,9 @@
 #else // _WIN32
 #include <dirent.h>
 #include <unistd.h>
+#ifndef __linux__
+#define stat64 stat
+#endif
 #endif // _WIN32
 
 namespace Utils
