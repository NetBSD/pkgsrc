$NetBSD: patch-Source_kwsys_Directory.cxx,v 1.1 2015/01/23 04:06:08 wiz Exp $

When opendir() fails, readdir() is called with a NULL pointer, leading to
a segfault.

http://public.kitware.com/Bug/view.php?id=15367

--- Source/kwsys/Directory.cxx.orig	2014-12-15 20:07:43.000000000 +0000
+++ Source/kwsys/Directory.cxx
@@ -240,11 +240,14 @@ unsigned long Directory::GetNumberOfFile
   DIR* dir = opendir(name.c_str());
 
   unsigned long count = 0;
-  for (dirent* d = readdir(dir); d; d = readdir(dir) )
+  if (dir)
     {
-    count++;
+    for (dirent* d = readdir(dir); d; d = readdir(dir) )
+      {
+      count++;
+      }
+    closedir(dir);
     }
-  closedir(dir);
   return count;
 }
 
