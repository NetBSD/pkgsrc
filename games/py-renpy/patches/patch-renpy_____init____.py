$NetBSD: patch-renpy_____init____.py,v 1.1 2023/03/10 21:14:39 ryoon Exp $

* Remove 'n' from version number to avoid invalid version number error.
  I should revisit this problem.

--- renpy/__init__.py.orig	2022-09-08 03:49:02.959533000 +0000
+++ renpy/__init__.py
@@ -98,7 +98,7 @@ else:
 version_only = ".".join(str(i) for i in version_tuple)
 
 if not official:
-    version_only += "u"
+    pass # version_only += "u"
 elif nightly:
     version_only += "n"
 
