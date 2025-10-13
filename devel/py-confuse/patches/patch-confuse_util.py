$NetBSD: patch-confuse_util.py,v 1.1 2025/10/13 12:28:04 wiz Exp $

address deprecation of  pkgutil.get_loader
https://github.com/beetbox/confuse/commit/ed79b4b9f53fe99293139c18f053168e564508b8

--- confuse/util.py.orig	2022-07-16 18:35:30.824052000 +0000
+++ confuse/util.py
@@ -1,9 +1,9 @@
+import importlib.util
 import os
 import sys
 import argparse
 import optparse
 import platform
-import pkgutil
 
 
 UNIX_DIR_FALLBACK = '~/.config'
@@ -114,8 +114,14 @@ def find_package_path(name):
     None if the path could not be identified (e.g., if
     ``name == "__main__"``).
     """
-    # Based on get_root_path from Flask by Armin Ronacher.
-    loader = pkgutil.get_loader(name)
+    # Based on get_root_path from Flask by Armin Ronacher, cf.
+    # https://github.com/pallets/flask/blob/85c5d93cbd049c4bd0679c36fd1ddcae8c37b642/src/flask/helpers.py#L570
+    try:
+        spec = importlib.util.find_spec(name)
+    except (ImportError, ValueError):
+        return None
+
+    loader = spec.loader
     if loader is None or name == '__main__':
         return None
 
