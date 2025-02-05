$NetBSD: patch-setup.py,v 1.8 2025/02/05 08:05:24 adam Exp $

Do not add debug symbols.
Do not override compiler optimiztion flags.
Avoid a hack.

--- setup.py.orig	2025-01-02 09:36:19.000000000 +0000
+++ setup.py
@@ -68,7 +68,6 @@ def get_sdk_level(sdk):
 
 # CFLAGS for the objc._objc extension:
 CFLAGS = [
-    "-g",
     "-fexceptions",
     # Explicitly opt-out of ARC
     "-fno-objc-arc",
@@ -91,13 +90,8 @@ CFLAGS = [
     "-Wshorten-64-to-32",
     # "-fsanitize=address", "-fsanitize=undefined", "-fno-sanitize=vptr",
     # "--analyze",
-    "-Werror",
     "-I/usr/include/ffi",
     "-fvisibility=hidden",
-    # "-O0",
-    "-g",
-    # "-O0",
-    "-O3",
     "-flto=thin",
     # XXX: Use object_path_lto (during linking?)
     "-UNDEBUG",
@@ -113,13 +107,9 @@ OBJC_LDFLAGS = [
     "-framework",
     "Foundation",
     # "-fvisibility=protected",
-    "-g",
     "-lffi",
     # "-fsanitize=address", "-fsanitize=undefined", "-fno-sanitize=vptr",
     "-fvisibility=hidden",
-    # "-O0",
-    "-g",
-    "-O3",
     "-flto=thin",
     "-fexceptions",
 ]
@@ -254,8 +244,6 @@ class oc_test(Command):
         self.__old_path = sys.path[:]
         self.__old_modules = sys.modules.copy()
 
-        if "PyObjCTools" in sys.modules:
-            del sys.modules["PyObjCTools"]
 
         ei_cmd = self.get_finalized_command("egg_info")
         sys.path.insert(0, normalize_path(ei_cmd.egg_base))
