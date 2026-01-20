$NetBSD: patch-setup.py,v 1.1 2026/01/20 22:31:28 wiz Exp $

No Python 2 compatibility needed.

--- setup.py.orig	2026-01-20 22:29:41.915826426 +0000
+++ setup.py
@@ -53,10 +53,6 @@ package_dir = {"": "src"}
 package_dir = {"": "src"}
 
 
-if any(arg.startswith("bdist") for arg in sys.argv):
-    import lib3to6
-    package_dir = lib3to6.fix(package_dir)
-
 
 setuptools.setup(
     name="lexid",
