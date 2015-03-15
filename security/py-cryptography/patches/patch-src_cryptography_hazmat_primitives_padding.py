$NetBSD: patch-src_cryptography_hazmat_primitives_padding.py,v 1.2 2015/03/15 21:10:16 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- src/cryptography/hazmat/primitives/padding.py.orig	2015-03-09 04:49:14.000000000 +0000
+++ src/cryptography/hazmat/primitives/padding.py
@@ -22,7 +22,7 @@ with open(os.path.join(os.path.dirname(_
     FUNCTIONS = f.read()
 
 
-_ffi = build_ffi(cdef_source=TYPES, verify_source=FUNCTIONS)
+_ffi = build_ffi(cdef_source=TYPES, verify_source=FUNCTIONS, module_name='padding')
 _lib = LazyLibrary(_ffi)
 
 
