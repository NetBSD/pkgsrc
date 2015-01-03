$NetBSD: patch-src_cryptography_hazmat_primitives_constant__time.py,v 1.1 2015/01/03 16:00:55 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- src/cryptography/hazmat/primitives/constant_time.py.orig	2014-12-29 01:46:47.000000000 +0000
+++ src/cryptography/hazmat/primitives/constant_time.py
@@ -17,7 +17,7 @@ with open(os.path.join(os.path.dirname(_
     FUNCTIONS = f.read()
 
 
-_ffi = build_ffi(cdef_source=TYPES, verify_source=FUNCTIONS)
+_ffi = build_ffi(cdef_source=TYPES, verify_source=FUNCTIONS, module_name='constanttime')
 _lib = LazyLibrary(_ffi)
 
 
