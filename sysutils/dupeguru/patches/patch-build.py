$NetBSD: patch-build.py,v 1.1 2020/01/26 12:55:00 rhialto Exp $

pyrcc5 is python-version-specific.

--- build.py.orig	2016-11-25 01:04:31.000000000 +0000
+++ build.py
@@ -164,7 +164,8 @@ def build_qt(dev):
     print("Building localizations")
     build_localizations('qt')
     print("Building Qt stuff")
-    print_and_do("pyrcc5 {0} > {1}".format(op.join('qt', 'dg.qrc'), op.join('qt', 'dg_rc.py')))
+    pyrcc5 = "pyrcc5-" + os.environ["PYVERSSUFFIX"]
+    print_and_do(pyrcc5 +" {0} > {1}".format(op.join('qt', 'dg.qrc'), op.join('qt', 'dg_rc.py')))
     fix_qt_resource_file(op.join('qt', 'dg_rc.py'))
     build_help()
     print("Creating the run.py file")
