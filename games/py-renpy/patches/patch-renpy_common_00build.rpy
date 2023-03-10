$NetBSD: patch-renpy_common_00build.rpy,v 1.1 2023/03/10 21:14:39 ryoon Exp $

* Fix compile with Python 3.11.
  From: https://github.com/renpy/renpy/commit/ccb075ea538b21d3ca2a21d2f04cd5de170789bc

--- renpy/common/00build.rpy.orig	2022-06-17 00:53:46.630644000 +0000
+++ renpy/common/00build.rpy
@@ -407,7 +407,7 @@ init -1500 python in build:
     package("steam", "zip", "windows linux mac renpy all", hidden=True)
     package("android", "directory", "android all", hidden=True, update=False, dlc=True)
     package("ios", "directory", "ios all", hidden=True, update=False, dlc=True)
-    package("web", "zip", "web all", hidden=True, update=False, dlc=True)
+    package("web", "zip", "web renpy all", hidden=True, update=False, dlc=True)
 
     # Data that we expect the user to set.
 
