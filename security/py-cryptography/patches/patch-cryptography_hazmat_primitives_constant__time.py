$NetBSD: patch-cryptography_hazmat_primitives_constant__time.py,v 1.2 2014/05/06 10:30:54 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- cryptography/hazmat/primitives/constant_time.py.orig	2014-05-03 14:19:18.000000000 +0000
+++ cryptography/hazmat/primitives/constant_time.py
@@ -51,7 +51,7 @@ _ffi = cffi.FFI()
 _ffi.cdef(TYPES)
 _lib = _ffi.verify(
     source=FUNCTIONS,
-    modulename=_create_modulename([TYPES], FUNCTIONS, sys.version),
+    modulename="constanttime",
     ext_package="cryptography",
 )
 
