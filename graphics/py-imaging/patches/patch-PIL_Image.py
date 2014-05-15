$NetBSD: patch-PIL_Image.py,v 1.1 2014/05/15 06:23:06 spz Exp $

patch for CVE-2014-1932 and CVE-2014-1933 taken from
https://github.com/python-imaging/Pillow/commit/4e9f367dfd3f04c8f5d23f7f759ec12782e10ee7

--- PIL/Image.py.orig	2009-11-15 15:51:25.000000000 +0000
+++ PIL/Image.py
@@ -482,14 +482,17 @@ class Image:
         self.readonly = 0
 
     def _dump(self, file=None, format=None):
-        import tempfile
+        import tempfile, os
         if not file:
-            file = tempfile.mktemp()
+            f, file = tempfile.mkstemp(format or '')
+            os.close(f)
+
         self.load()
         if not format or format == "PPM":
             self.im.save_ppm(file)
         else:
-            file = file + "." + format
+            if file.endswith(format):
+                file = file + "." + format
             self.save(file, format)
         return file
 
