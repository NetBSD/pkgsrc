$NetBSD: patch-src_cryptography_hazmat_primitives_padding.py,v 1.1 2015/01/03 16:00:55 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- src/cryptography/hazmat/primitives/padding.py.orig	2014-12-29 01:46:47.000000000 +0000
+++ src/cryptography/hazmat/primitives/padding.py
@@ -55,7 +55,7 @@ uint8_t Cryptography_check_pkcs7_padding
 """
 
 
-_ffi = build_ffi(cdef_source=TYPES, verify_source=FUNCTIONS)
+_ffi = build_ffi(cdef_source=TYPES, verify_source=FUNCTIONS, module_name='padding')
 _lib = LazyLibrary(_ffi)
 
 
