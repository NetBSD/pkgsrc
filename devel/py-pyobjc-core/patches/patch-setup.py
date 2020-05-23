$NetBSD: patch-setup.py,v 1.2 2020/05/23 07:03:41 adam Exp $

Do not add debug symbols.
Do not override compiler optimiztion flags.
Avoid a hack.

--- setup.py.orig	2020-03-22 17:36:26.000000000 +0000
+++ setup.py
@@ -56,7 +56,6 @@ def get_sdk_level(sdk):
 
 # CFLAGS for the objc._objc extension:
 CFLAGS = [
-    "-g",
     "-fexceptions",
     # Loads of warning flags
     "-Wall",
@@ -126,7 +125,7 @@ if get_config_var("Py_DEBUG"):
         elif isinstance(cfg_vars[k], str) and "-O3" in cfg_vars[k]:
             cfg_vars[k] = cfg_vars[k].replace("-O3", "-O1 -g")
 
-else:
+elif False:
     # Enable -O4, which enables link-time optimization with
     # clang. This appears to have a positive effect on performance.
     cfg_vars = get_config_vars()
@@ -247,8 +246,6 @@ class oc_test(test.test):
         self.__old_path = sys.path[:]
         self.__old_modules = sys.modules.copy()
 
-        if "PyObjCTools" in sys.modules:
-            del sys.modules["PyObjCTools"]
 
         ei_cmd = self.get_finalized_command("egg_info")
         sys.path.insert(0, normalize_path(ei_cmd.egg_base))
