$NetBSD: patch-qt_platform.py,v 1.1 2017/09/26 11:22:39 wiz Exp $

Instead of failing on unknown platforms, assume them to be Unix-style.
https://github.com/hsoft/dupeguru/issues/444

--- qt/platform.py.orig	2016-11-25 01:04:31.000000000 +0000
+++ qt/platform.py
@@ -23,4 +23,4 @@ elif ISOSX:
 elif ISLINUX:
     INITIAL_FOLDER_IN_DIALOGS = '/'
 else:
-    pass # unsupported platform
+    INITIAL_FOLDER_IN_DIALOGS = '/'
