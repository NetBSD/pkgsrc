$NetBSD: patch-setup.py,v 1.1 2023/07/29 15:36:28 adam Exp $

Fix for Python 3.8.
https://github.com/HypothesisWorks/hypothesis/issues/3707

--- setup.py.orig	2023-07-29 15:30:00.000000000 +0000
+++ setup.py
@@ -25,7 +25,7 @@ if sys.version_info[:2] < (3, 8):
 
 
 def local_file(name):
-    return Path(__file__).parent.joinpath(name).relative_to(Path.cwd())
+    return Path(__file__).absolute().parent.joinpath(name).relative_to(Path.cwd())
 
 
 SOURCE = str(local_file("src"))
