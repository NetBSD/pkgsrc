$NetBSD: patch-nihtest_File.py,v 1.1 2024/01/03 16:28:37 wiz Exp $

Use absolute path.
https://github.com/nih-at/nihtest/commit/9629144acbe2c7ff07a43035b3f885d5fbc8f0d9

--- nihtest/File.py.orig	2024-01-03 16:27:03.810550090 +0000
+++ nihtest/File.py
@@ -23,7 +23,7 @@ class File:
         self.result = result
 
     def file_name(self, directory):
-        return sandbox.sub(directory, self.name)
+        return sandbox.sub(os.path.abspath(directory), self.name)
 
     def compare(self, configuration, directory):
         if not self.result:
