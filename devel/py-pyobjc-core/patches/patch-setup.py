$NetBSD: patch-setup.py,v 1.1 2019/11/18 17:05:06 adam Exp $

Do not add debug symbols.
Do not override compiler optimiztion flags.

--- setup.py.orig	2019-11-18 16:02:47.000000000 +0000
+++ setup.py
@@ -66,7 +66,6 @@ def get_sdk_level(sdk):
 
 # CFLAGS for the objc._objc extension:
 CFLAGS = [
-    "-g",
     "-fexceptions",
     # Loads of warning flags
     "-Wall",
@@ -137,7 +136,7 @@ if get_config_var("Py_DEBUG"):
         elif isinstance(cfg_vars[k], str) and "-O3" in cfg_vars[k]:
             cfg_vars[k] = cfg_vars[k].replace("-O3", "-O1 -g")
 
-else:
+elif False:
     # Enable -O4, which enables link-time optimization with
     # clang. This appears to have a positive effect on performance.
     cfg_vars = get_config_vars()
