$NetBSD: patch-build__pynng.py,v 1.1 2021/05/13 19:35:54 khorben Exp $

Fix build on NetBSD

--- build_pynng.py.orig	2020-12-17 03:54:43.000000000 +0000
+++ build_pynng.py
@@ -28,8 +28,8 @@ else:
     machine = os.uname().machine
     # this is a pretty heuristic... but let's go with it anyway.
     # it would be better to get linker information from cmake somehow.
-    if not ('x86' in machine or 'i386' in machine or 'i686' in machine):
-        libraries.append('atomic')
+    #if not ('x86' in machine or 'i386' in machine or 'i686' in machine):
+    #    libraries.append('atomic')
 
 
 ffibuilder.set_source(
