$NetBSD: patch-module_setuplib.py,v 1.1 2023/03/10 21:14:39 ryoon Exp $

* Fix for Python 3.11.

--- module/setuplib.py.orig	2022-06-21 00:46:56.861042500 +0000
+++ module/setuplib.py
@@ -53,6 +53,9 @@ gen = "gen"
 
 if sys.version_info.major > 2:
     gen += "3"
+    PY2 = False
+else:
+    PY2 = True
 
 if coverage:
     gen += "-coverage"
