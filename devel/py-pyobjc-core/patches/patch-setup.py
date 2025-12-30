$NetBSD: patch-setup.py,v 1.10 2025/12/30 14:18:13 adam Exp $

Do not add debug symbols.
Do not override compiler optimiztion flags.
Avoid a hack.

--- setup.py.orig	2025-11-01 07:21:30.000000000 +0000
+++ setup.py
@@ -67,7 +67,6 @@ def get_sdk_level(sdk):
 
 # CFLAGS for the objc._objc extension:
 CFLAGS = [
-    "-g",
     "-fexceptions",
     # Explicitly opt-out of ARC
     "-fno-objc-arc",
@@ -94,10 +93,6 @@ CFLAGS = [
     "-Wno-cast-function-type-mismatch",
     "-I/usr/include/ffi",
     "-fvisibility=hidden",
-    # "-O0",
-    "-g",
-    # "-O0",
-    "-O3",
     "-flto=thin",
     # XXX: Use object_path_lto (during linking?)
     # "-fsanitize-thread-atomics",
@@ -113,13 +108,9 @@ OBJC_LDFLAGS = [
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
     # "-O0",
     "-fexceptions",
@@ -252,8 +243,6 @@ class oc_test(Command):
         self.__old_path = sys.path[:]
         self.__old_modules = sys.modules.copy()
 
-        if "PyObjCTools" in sys.modules:
-            del sys.modules["PyObjCTools"]
 
         ei_cmd = self.get_finalized_command("egg_info")
         sys.path.insert(0, os.path.abspath(ei_cmd.egg_base))
