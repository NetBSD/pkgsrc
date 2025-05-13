$NetBSD: patch-tests_test__unix.py,v 1.1 2025/05/13 13:26:50 riastradh Exp $

Fix tests on BSD.  Resolves:

FAILED tests/test_unix.py::test_xdg_variable_not_set[user_runtime_dir] - AssertionError: assert '/tmp/runtime-1234' == '/run/user/1234'
FAILED tests/test_unix.py::test_xdg_variable_not_set[site_runtime_dir] - AssertionError: assert '/var/run' == '/run'
FAILED tests/test_unix.py::test_xdg_variable_empty_value[user_runtime_dir] - AssertionError: assert '/tmp/runtime-1234' == '/run/user/1234'
FAILED tests/test_unix.py::test_xdg_variable_empty_value[site_runtime_dir] - AssertionError: assert '/var/run' == '/run'

--- tests/test_unix.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ tests/test_unix.py
@@ -89,6 +89,12 @@ class XDGVariable(typing.NamedTuple):
 
 
 def _func_to_path(func: str) -> XDGVariable | None:
+    if sys.platform.startswith(("freebsd", "openbsd", "netbsd")):
+        user_default = '/tmp/runtime-1234'
+        site_default = '/var/run'
+    else:
+        user_default = '/run/user/1234'
+        site_default = '/run'
     mapping = {
         "user_data_dir": XDGVariable("XDG_DATA_HOME", "~/.local/share"),
         "site_data_dir": XDGVariable("XDG_DATA_DIRS", f"/usr/local/share{os.pathsep}/usr/share"),
@@ -97,8 +103,8 @@ def _func_to_path(func: str) -> XDGVaria
         "user_cache_dir": XDGVariable("XDG_CACHE_HOME", "~/.cache"),
         "user_state_dir": XDGVariable("XDG_STATE_HOME", "~/.local/state"),
         "user_log_dir": XDGVariable("XDG_STATE_HOME", "~/.local/state"),
-        "user_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", "/run/user/1234"),
-        "site_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", "/run"),
+        "user_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", user_default),
+        "site_runtime_dir": XDGVariable("XDG_RUNTIME_DIR", site_default),
     }
     return mapping.get(func)
 
