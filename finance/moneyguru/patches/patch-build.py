$NetBSD: patch-build.py,v 1.1 2020/01/26 12:55:01 rhialto Exp $

pyrcc5 is python-version-specific.

--- build.py.orig	2017-08-23 23:26:50.000000000 +0000
+++ build.py
@@ -81,9 +81,10 @@ def clean():
 def build_qt(dev):
     qrc_path = op.join('qt', 'mg.qrc')
     pyrc_path = op.join('qt', 'mg_rc.py')
-    ret = print_and_do("pyrcc5 {} > {}".format(qrc_path, pyrc_path))
+    pyrcc5 = "pyrcc5-" + os.environ["PYVERSSUFFIX"]
+    ret = print_and_do(pyrcc5 +" {} > {}".format(qrc_path, pyrc_path))
     if ret != 0:
-        raise RuntimeError("pyrcc5 call failed with code {}. Aborting build".format(ret))
+        raise RuntimeError(pyrcc5 + " call failed with code {}. Aborting build".format(ret))
     build_help()
 
 def build_help():
