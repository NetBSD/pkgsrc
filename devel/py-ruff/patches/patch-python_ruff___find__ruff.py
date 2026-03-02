$NetBSD: patch-python_ruff___find__ruff.py,v 1.1 2026/03/02 08:31:09 adam Exp $

Find Ruff binary with Python version suffix.

--- python/ruff/_find_ruff.py.orig	2006-07-24 01:21:28.000000000 +0000
+++ python/ruff/_find_ruff.py
@@ -48,6 +48,16 @@ def find_ruff_bin() -> str:
         path = os.path.join(target, ruff_exe)
         if os.path.isfile(path):
             return path
+        path = os.path.join(
+            target
+            + "-"
+            + str(sys.version_info.major)
+            + "."
+            + str(sys.version_info.minor),
+            ruff_exe,
+        )
+        if os.path.isfile(path):
+            return path
 
     locations = "\n".join(f" - {target}" for target in seen)
     raise RuffNotFound(
