$NetBSD: patch-electrum-ecc_fast.py,v 1.1 2020/11/04 20:45:46 js Exp $

Don't assume libsecp256k1 is in site-packages/electrum.

--- electrum/ecc_fast.py.orig	2000-11-11 11:11:11.000000000 +0000
+++ electrum/ecc_fast.py
@@ -9,6 +9,7 @@ from ctypes import (
     byref, c_byte, c_int, c_uint, c_char_p, c_size_t, c_void_p, create_string_buffer,
     CFUNCTYPE, POINTER, cast
 )
+import sysconfig
 
 from .logging import get_logger
 
@@ -38,16 +39,13 @@ class LibModuleMissing(Exception): pass
 
 def load_library():
     if sys.platform == 'darwin':
-        library_paths = (os.path.join(os.path.dirname(__file__), 'libsecp256k1.0.dylib'),
-                         'libsecp256k1.0.dylib')
+        library_paths = (os.path.join(sysconfig.get_config_var('LIBDIR'), 'libsecp256k1.0.dylib'),)
     elif sys.platform in ('windows', 'win32'):
-        library_paths = (os.path.join(os.path.dirname(__file__), 'libsecp256k1-0.dll'),
-                         'libsecp256k1-0.dll')
+        library_paths = (os.path.join(sysconfig.get_config_var('LIBDIR'), 'libsecp256k1-0.dll'),)
     elif 'ANDROID_DATA' in os.environ:
         library_paths = ('libsecp256k1.so',)
     else:  # desktop Linux and similar
-        library_paths = (os.path.join(os.path.dirname(__file__), 'libsecp256k1.so.0'),
-                         'libsecp256k1.so.0')
+        library_paths = (os.patah.join(sysconfig.get_config_var('LIBDIR'), 'libsecp256k1.so.0'),)
 
     exceptions = []
     secp256k1 = None
