$NetBSD: patch-Lib_plistlib.py,v 1.1 2018/06/17 19:21:21 adam Exp $

Add ability to parse unsigned integers as externalized by NetBSD proplib(3).

--- Lib/plistlib.py.orig	2014-12-10 15:59:39.000000000 +0000
+++ Lib/plistlib.py
@@ -463,7 +463,7 @@ class PlistParser:
     def end_false(self):
         self.addObject(False)
     def end_integer(self):
-        self.addObject(int(self.getData()))
+        self.addObject(int(self.getData(), 0))
     def end_real(self):
         self.addObject(float(self.getData()))
     def end_string(self):
