$NetBSD: patch-magic_loader.py,v 1.3 2021/09/14 20:23:04 js Exp $

Make py-magic work in a chroot on NetBSD.

--- magic/loader.py.orig	2021-06-03 13:42:29.000000000 +0000
+++ magic/loader.py
@@ -33,6 +33,9 @@ def _lib_candidates():
     # This is necessary because alpine is bad
     yield 'libmagic.so.1'
 
+  elif sys.platform.startswith('netbsd'):
+    yield 'libmagic.so'
+
 
 def load_lib():
 
