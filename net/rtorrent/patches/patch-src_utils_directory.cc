$NetBSD: patch-src_utils_directory.cc,v 1.1 2018/06/24 16:59:52 adam Exp $

Fix build under DragonFly.

--- src/utils/directory.cc.orig	2014-04-21 14:34:45.000000000 +0100
+++ src/utils/directory.cc	2014-06-15 21:07:36.000000000 +0100
@@ -44,6 +44,10 @@
 #include <rak/path.h>
 #include <torrent/exceptions.h>
 
+#ifdef __DragonFly__
+#define d_reclen d_namlen
+#endif
+
 #include "directory.h"
 
 namespace utils {
@@ -54,7 +58,9 @@
   if (m_path.empty())
     return false;
 
-  DIR* d = opendir(rak::path_expand(m_path).c_str());
+  std::string path=rak::path_expand(m_path);
+
+  DIR* d = opendir(path.c_str());
   closedir(d);
 
   return d;
@@ -65,7 +71,9 @@
   if (m_path.empty())
     throw torrent::input_error("Directory::update() tried to open an empty path.");
 
-  DIR* d = opendir(rak::path_expand(m_path).c_str());
+  std::string path=rak::path_expand(m_path);
+
+  DIR* d = opendir(path.c_str());
 
   if (d == NULL)
     return false;
