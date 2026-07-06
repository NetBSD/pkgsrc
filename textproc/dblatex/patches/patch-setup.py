$NetBSD: patch-setup.py,v 1.1 2026/07/06 12:36:38 adam Exp $

Use Python absolute path directly in the script.

--- setup.py.orig	2020-11-29 17:50:08.000000000 +0000
+++ setup.py
@@ -109,7 +109,7 @@ os.environ["SGML_CATALOG_FILES"] = cat
         ENV_BIN = '/usr/bin/env'
         env_args = ''
         py_exec_bname = os.path.basename(sys.executable)
-        if self._use_py_path:
+        if True:
             env_exec = ''
             py_exec = sys.executable
         elif os.name == 'posix':
