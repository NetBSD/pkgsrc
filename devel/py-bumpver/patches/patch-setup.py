$NetBSD: patch-setup.py,v 1.1 2026/01/20 22:34:36 wiz Exp $

Python 2 compatibility not needed.

--- setup.py.orig	2026-01-20 22:31:52.973901112 +0000
+++ setup.py
@@ -57,11 +57,6 @@ package_dir = {"": "src"}
 package_dir = {"": "src"}
 
 
-if any(arg.startswith("bdist") for arg in sys.argv):
-    import lib3to6
-    package_dir = lib3to6.fix(package_dir)
-
-
 setuptools.setup(
     name="bumpver",
     license="MIT",
