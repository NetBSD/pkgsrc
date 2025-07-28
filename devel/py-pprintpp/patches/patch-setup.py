$NetBSD: patch-setup.py,v 1.1 2025/07/28 20:17:13 dkazankov Exp $

Fix build error

--- setup.py.orig	2018-07-01 04:42:25.000000000 +0300
+++ setup.py
@@ -8,7 +8,7 @@
 os.chdir(os.path.dirname(sys.argv[0]) or ".")
 
 try:
-    long_description = open("README.rst", "U").read()
+    long_description = open("README.rst").read()
 except IOError:
     long_description = "See https://github.com/wolever/pprintpp"
 
