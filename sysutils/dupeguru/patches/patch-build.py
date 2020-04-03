$NetBSD: patch-build.py,v 1.2 2020/04/03 21:59:48 wiz Exp $

pyrcc5 is python-version-specific.

--- build.py.orig	2019-05-14 01:43:47.000000000 +0000
+++ build.py
@@ -125,7 +125,8 @@ def build_normal():
     print("Building localizations")
     build_localizations()
     print("Building Qt stuff")
-    print_and_do("pyrcc5 {0} > {1}".format(op.join('qt', 'dg.qrc'), op.join('qt', 'dg_rc.py')))
+    pyrcc5 = "pyrcc5-" + os.environ["PYVERSSUFFIX"]
+    print_and_do(pyrcc5 +" {0} > {1}".format(op.join('qt', 'dg.qrc'), op.join('qt', 'dg_rc.py')))
     fix_qt_resource_file(op.join('qt', 'dg_rc.py'))
     build_help()
 
