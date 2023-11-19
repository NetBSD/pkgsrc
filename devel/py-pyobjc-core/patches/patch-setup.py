$NetBSD: patch-setup.py,v 1.6 2023/11/19 17:02:49 adam Exp $

Do not add debug symbols.
Do not override compiler optimiztion flags.
Avoid a hack.

--- setup.py.orig	2023-09-16 12:35:53.000000000 +0000
+++ setup.py
@@ -67,7 +67,6 @@ def get_sdk_level(sdk):
 
 # CFLAGS for the objc._objc extension:
 CFLAGS = [
-    "-g",
     "-fexceptions",
     # Explicitly opt-out of ARC
     "-fno-objc-arc",
@@ -89,10 +88,6 @@ CFLAGS = [
     "-Werror",
     "-I/usr/include/ffi",
     "-fvisibility=hidden",
-    # "-O0",
-    "-g",
-    # "-O0",
-    "-O3",
     "-flto=thin",
     # XXX: Use object_path_lto (during linking?)
     "-UNDEBUG",
@@ -113,8 +108,6 @@ OBJC_LDFLAGS = [
     # "-fsanitize=address", "-fsanitize=undefined", "-fno-sanitize=vptr",
     "-fvisibility=hidden",
     # "-O0",
-    "-g",
-    "-O3",
     "-flto=thin",
     "-fexceptions",
 ]
@@ -253,8 +246,6 @@ class oc_test(test.test):
         self.__old_path = sys.path[:]
         self.__old_modules = sys.modules.copy()
 
-        if "PyObjCTools" in sys.modules:
-            del sys.modules["PyObjCTools"]
 
         ei_cmd = self.get_finalized_command("egg_info")
         sys.path.insert(0, normalize_path(ei_cmd.egg_base))
