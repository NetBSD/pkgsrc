$NetBSD: patch-tests_list-tree.py,v 1.1 2018/01/10 19:32:13 wiz Exp $

From upstream:
tests: write and use a custom helper script to avoid find's -printf.

--- tests/list-tree.py.orig	2018-01-10 14:21:58.440677374 +0000
+++ tests/list-tree.py
@@ -0,0 +1,27 @@
+from __future__ import (
+    absolute_import,
+    print_function,
+)
+
+import argparse
+import os
+
+ap = argparse.ArgumentParser()
+ap.add_argument('path', nargs='+')
+opts = ap.parse_args()
+
+def gather():
+    for p in opts.path:
+        if not os.path.exists(p):
+            return
+        if os.path.isdir(p):
+            yield p + os.path.sep
+            for dirpath, dirs, files in os.walk(p):
+                for d in dirs:
+                    yield os.path.join(dirpath, d) + os.path.sep
+                for f in files:
+                    yield os.path.join(dirpath, f)
+        else:
+            yield p
+
+print('\n'.join(sorted(gather())))
