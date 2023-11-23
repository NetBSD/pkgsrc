$NetBSD: patch-renpy_____init____.py,v 1.2 2023/11/23 15:41:21 ryoon Exp $

* Remove 'n' from version number to avoid invalid version number error.
  I should revisit this problem.

--- renpy/__init__.py.orig	2023-09-18 22:22:33.609540000 +0000
+++ renpy/__init__.py
@@ -94,7 +94,7 @@ version_tuple = VersionTuple(*(int(i) fo
 version_only = ".".join(str(i) for i in version_tuple)
 
 if not official:
-    version_only += "+unofficial"
+    pass
 elif nightly:
     version_only += "+nightly"
 
