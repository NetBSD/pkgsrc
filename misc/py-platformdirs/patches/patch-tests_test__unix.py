$NetBSD: patch-tests_test__unix.py,v 1.3 2026/02/16 11:44:01 wiz Exp $

Fix tests on BSD.
https://github.com/tox-dev/platformdirs/issues/449

--- tests/test_unix.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ tests/test_unix.py
@@ -96,6 +96,10 @@ def _func_to_path(func: str) -> XDGVariable | None:
 
 
 def _func_to_path(func: str) -> XDGVariable | None:
+    if sys.platform.startswith(("freebsd", "openbsd", "netbsd")):
+        site_default = '/var/run'
+    else:
+        site_default = '/run'
     mapping = {
         "user_data_dir": XDGVariable("XDG_DATA_HOME", "~/.local/share"),
         "site_data_dir": XDGVariable("XDG_DATA_DIRS", f"/usr/local/share{os.pathsep}/usr/share"),
@@ -111,7 +115,7 @@ def _func_to_path(func: str) -> XDGVariable | None:
         "site_applications_dir": None,
         "site_log_dir": None,
         "site_state_dir": None,
-        "site_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", "/run"),
+        "site_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", site_default),
     }
     return mapping.get(func)
 
