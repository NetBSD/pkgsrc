$NetBSD: patch-Source_kwsys_Directory.cxx,v 1.2 2015/02/05 17:45:22 adam Exp $

When opendir() fails, readdir() is called with a NULL pointer, leading to
a segfault.

http://public.kitware.com/Bug/view.php?id=15367

--- Source/kwsys/Directory.cxx.orig	2015-02-04 20:36:44.000000000 +0000
+++ Source/kwsys/Directory.cxx
@@ -245,11 +245,14 @@ unsigned long Directory::GetNumberOfFile
     }
 
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
 
