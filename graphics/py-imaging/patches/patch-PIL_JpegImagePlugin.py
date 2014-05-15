$NetBSD: patch-PIL_JpegImagePlugin.py,v 1.1 2014/05/15 06:23:06 spz Exp $

patch for CVE-2014-1932 and CVE-2014-1933 taken from
https://github.com/python-imaging/Pillow/commit/4e9f367dfd3f04c8f5d23f7f759ec12782e10ee7

--- PIL/JpegImagePlugin.py.orig	2009-11-01 00:44:12.000000000 +0000
+++ PIL/JpegImagePlugin.py
@@ -344,13 +344,17 @@ class JpegImageFile(ImageFile.ImageFile)
         # ALTERNATIVE: handle JPEGs via the IJG command line utilities
 
         import tempfile, os
-        file = tempfile.mktemp()
-        os.system("djpeg %s >%s" % (self.filename, file))
+        f, path = tempfile.mkstemp()
+        os.close(f)
+        if os.path.exists(self.filename):
+            os.system("djpeg '%s' >'%s'" % (self.filename, path))
+        else:
+            raise ValueError("Invalid Filename")
 
         try:
-            self.im = Image.core.open_ppm(file)
+            self.im = Image.core.open_ppm(path)
         finally:
-            try: os.unlink(file)
+            try: os.unlink(path)
             except: pass
 
         self.mode = self.im.mode
