$NetBSD: patch-src_system.cpp,v 1.1 2011/08/14 19:13:03 wiz Exp $

Fix build with gcc-4.5.

--- src/system.cpp.orig	2007-10-31 03:16:57.000000000 +0000
+++ src/system.cpp
@@ -548,8 +548,8 @@ System::realpath(const std::string& path
 #endif
   else
     {
-      char buf[PATH_MAX];
-      if (getcwd(buf, PATH_MAX) == 0)
+      char buf[FILENAME_MAX];
+      if (getcwd(buf, FILENAME_MAX) == 0)
         {
           std::cout << "System::realpath: Error: couldn't getcwd()" << std::endl;
           return pathname;
