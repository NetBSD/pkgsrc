$NetBSD: patch-python_ruff_____main____.py,v 1.1 2024/11/17 12:49:52 adam Exp $

Find Ruff binary with Python version suffix.

--- python/ruff/__main__.py.orig	2024-11-17 12:32:50.193936982 +0000
+++ python/ruff/__main__.py
@@ -11,6 +11,9 @@ def find_ruff_bin() -> str:
     scripts_path = os.path.join(sysconfig.get_path("scripts"), ruff_exe)
     if os.path.isfile(scripts_path):
         return scripts_path
+    scripts_path += "-" + str(sys.version_info.major) + "." + str(sys.version_info.minor)
+    if os.path.isfile(scripts_path):
+        return scripts_path
 
     if sys.version_info >= (3, 10):
         user_scheme = sysconfig.get_preferred_scheme("user")
