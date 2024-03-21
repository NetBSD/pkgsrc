$NetBSD: patch-maturin_____init____.py,v 1.3 2024/03/21 20:00:28 adam Exp $

Look for correct command with ${PYVERSSUFFIX} appended.

--- maturin/__init__.py.orig	2024-03-21 12:31:15.000000000 +0000
+++ maturin/__init__.py
@@ -63,8 +63,9 @@ def _build_wheel(
 ) -> str:
     # PEP 517 specifies that only `sys.executable` points to the correct
     # python interpreter
+    py_vers = platform.python_version_tuple()
     base_command = [
-        "maturin",
+        "maturin-" + py_vers[0] + "." + py_vers[1],
         "pep517",
         "build-wheel",
         "-i",
