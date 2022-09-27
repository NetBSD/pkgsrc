$NetBSD: patch-setup.py,v 1.3 2022/09/27 18:12:46 adam Exp $

Do not add debug symbols.
Do not override compiler optimiztion flags.
Avoid a hack.

--- setup.py.orig	2022-08-12 08:06:27.000000000 +0000
+++ setup.py
@@ -67,7 +67,6 @@ def get_sdk_level(sdk):
 
 # CFLAGS for the objc._objc extension:
 CFLAGS = [
-    "-g",
     "-fexceptions",
     # Explicitly opt-out of ARC
     "-fno-objc-arc",
@@ -90,8 +89,6 @@ CFLAGS = [
     "-I/usr/include/ffi",
     "-fvisibility=hidden",
     # "-O0",
-    "-g",
-    "-O3",
     "-flto=thin",
 ]
 
@@ -105,13 +102,10 @@ OBJC_LDFLAGS = [
     "-framework",
     "Foundation",
     # "-fvisibility=protected",
-    "-g",
     "-lffi",
     # "-fsanitize=address", "-fsanitize=undefined", "-fno-sanitize=vptr",
     "-fvisibility=hidden",
     # "-O0",
-    "-g",
-    "-O3",
     "-flto=thin",
 ]
 
@@ -249,8 +243,6 @@ class oc_test(test.test):
         self.__old_path = sys.path[:]
         self.__old_modules = sys.modules.copy()
 
-        if "PyObjCTools" in sys.modules:
-            del sys.modules["PyObjCTools"]
 
         ei_cmd = self.get_finalized_command("egg_info")
         sys.path.insert(0, normalize_path(ei_cmd.egg_base))
