$NetBSD: patch-maturin_____init____.py,v 1.4 2026/05/10 07:40:11 adam Exp $

Look for correct command with ${PYVERSSUFFIX} appended.

--- maturin/__init__.py.orig	2006-07-24 01:21:28.000000000 +0000
+++ maturin/__init__.py
@@ -95,7 +95,8 @@ def _build_wheel(
 ) -> str:
     # PEP 517 specifies that only `sys.executable` points to the correct
     # python interpreter
-    base_command = ["maturin", "pep517", "build-wheel"]
+    py_vers = platform.python_version_tuple()
+    base_command = ["maturin-" + py_vers[0] + "." + py_vers[1], "pep517", "build-wheel"]
     options = _additional_pep517_args()
     if editable:
         options.append("--editable")
