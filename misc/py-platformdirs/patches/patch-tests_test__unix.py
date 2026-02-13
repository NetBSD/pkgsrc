$NetBSD: patch-tests_test__unix.py,v 1.2 2026/02/13 09:30:07 adam Exp $

Fix tests on BSD.

--- tests/test_unix.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ tests/test_unix.py
@@ -96,6 +96,10 @@ class XDGVariable(typing.NamedTuple):
 
 
 def _func_to_path(func: str) -> XDGVariable | None:
+    if sys.platform.startswith(("freebsd", "openbsd", "netbsd")):
+        site_default = '/var/run'
+    else:
+        site_default = '/run'
     mapping = {
         "user_data_dir": XDGVariable("XDG_DATA_HOME", "~/.local/share"),
         "site_data_dir": XDGVariable("XDG_DATA_DIRS", f"/usr/local/share{os.pathsep}/usr/share"),
@@ -105,7 +109,7 @@ def _func_to_path(func: str) -> XDGVaria
         "user_state_dir": XDGVariable("XDG_STATE_HOME", "~/.local/state"),
         "user_log_dir": XDGVariable("XDG_STATE_HOME", "~/.local/state"),
         "user_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", f"{gettempdir()}/runtime-1234"),
-        "site_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", "/run"),
+        "site_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", site_default),
     }
     return mapping.get(func)
 
