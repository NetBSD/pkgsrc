$NetBSD: patch-maturin_____init____.py,v 1.1 2023/03/03 08:57:14 adam Exp $

Look for correct command with ${PYVERSSUFFIX} appended.

--- maturin/__init__.py.orig	2023-03-03 08:36:13.000000000 +0000
+++ maturin/__init__.py
@@ -51,8 +51,9 @@ def _build_wheel(
 ):
     # PEP 517 specifies that only `sys.executable` points to the correct
     # python interpreter
+    py_vers = platform.python_version_tuple()
     command = [
-        "maturin",
+        "maturin-" + py_vers[0] + "." + py_vers[1],
         "pep517",
         "build-wheel",
         "-i",
