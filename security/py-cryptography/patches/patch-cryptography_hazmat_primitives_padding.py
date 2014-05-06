$NetBSD: patch-cryptography_hazmat_primitives_padding.py,v 1.2 2014/05/06 10:30:54 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- cryptography/hazmat/primitives/padding.py.orig	2014-05-03 14:19:18.000000000 +0000
+++ cryptography/hazmat/primitives/padding.py
@@ -71,7 +71,7 @@ _ffi = cffi.FFI()
 _ffi.cdef(TYPES)
 _lib = _ffi.verify(
     source=FUNCTIONS,
-    modulename=_create_modulename([TYPES], FUNCTIONS, sys.version),
+    modulename="checkpkcs7padding",
     ext_package="cryptography",
 )
 
