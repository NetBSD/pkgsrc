$NetBSD: patch-scripts_package__build.py,v 1.1 2025/06/24 00:02:58 ryoon Exp $

--- scripts/package_build.py.orig	2025-06-23 10:23:12.773672554 +0000
+++ scripts/package_build.py
@@ -206,7 +206,7 @@ def git_dev_version():
         dev_version = long_version.split('-')[1]
         if int(dev_version) == 0:
             # directly on a tag: emit the regular version
-            return "v" + '.'.join(version_splits)
+            return "v@PKGVERSION_NOREV@"
         else:
             # not on a tag: increment the version by one and add a -devX suffix
             # this needs to keep in sync with changes to CMakeLists.txt
