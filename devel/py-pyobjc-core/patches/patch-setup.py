$NetBSD: patch-setup.py,v 1.11 2026/06/03 11:44:00 adam Exp $

Do not add debug symbols.
Do not override compiler optimiztion flags.
Avoid a hack.

--- setup.py.orig	2026-01-25 10:49:01.000000000 +0000
+++ setup.py
@@ -67,7 +67,6 @@ def get_sdk_level(sdk):
 
 # CFLAGS for the objc._objc extension:
 CFLAGS = [
-    "-g",
     "-fexceptions",
     # Explicitly opt-out of ARC
     "-fno-objc-arc",
@@ -94,9 +93,6 @@ CFLAGS = [
     "-Wno-cast-function-type-mismatch",
     "-I/usr/include/ffi",
     "-fvisibility=hidden",
-    "-g",
-    # "-O0",
-    "-O3",
 ]
 
 # CFLAGS for other (test) extensions:
@@ -112,9 +108,6 @@ OBJC_LDFLAGS = [
     # "-fvisibility=protected",
     "-lffi",
     "-fvisibility=hidden",
-    "-g",
-    # "-O0",
-    "-O3",
     "-fexceptions",
 ]
 EXT_LDFLAGS = OBJC_LDFLAGS + []
@@ -246,8 +239,6 @@ class oc_test(Command):
         self.__old_path = sys.path[:]
         self.__old_modules = sys.modules.copy()
 
-        if "PyObjCTools" in sys.modules:
-            del sys.modules["PyObjCTools"]
 
         ei_cmd = self.get_finalized_command("egg_info")
         sys.path.insert(0, os.path.abspath(ei_cmd.egg_base))
