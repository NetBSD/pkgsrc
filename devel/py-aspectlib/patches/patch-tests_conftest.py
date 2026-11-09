$NetBSD: patch-tests_conftest.py,v 1.1 2026/11/09 09:29:29 wiz Exp $

https://github.com/ionelmc/python-aspectlib/blob/master/tests/conftest.py

--- tests/conftest.py.orig	2026-11-09 08:29:56.903996473 +0000
+++ tests/conftest.py
@@ -1,5 +1,6 @@
-def pytest_ignore_collect(path, config):
-    basename = path.basename
+from pathlib import Path
 
-    if 'pytestsupport' in basename:
+
+def pytest_ignore_collect(collection_path: Path, config):
+    if 'pytestsupport' in collection_path.__fspath__():
         return True
