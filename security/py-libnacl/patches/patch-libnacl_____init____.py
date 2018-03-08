$NetBSD: patch-libnacl_____init____.py,v 1.1 2018/03/08 08:13:04 adam Exp $

Use correct path to load libsodium.

--- libnacl/__init__.py.orig	2018-03-06 14:26:45.000000000 +0000
+++ libnacl/__init__.py
@@ -38,6 +38,10 @@ def _get_nacl():
         except OSError:
             pass
         try:
+            return ctypes.cdll.LoadLibrary('@PREFIX@/lib/libsodium.dylib')
+        except OSError:
+            pass
+        try:
             libidx = __file__.find('lib')
             if libidx > 0:
                 libpath = __file__[0:libidx+3] + '/libsodium.dylib'
@@ -51,7 +55,7 @@ def _get_nacl():
         except OSError:
             pass
         try:
-            return ctypes.cdll.LoadLibrary('/usr/local/lib/libsodium.so')
+            return ctypes.cdll.LoadLibrary('@PREFIX@/lib/libsodium.so')
         except OSError:
             pass
         try:
