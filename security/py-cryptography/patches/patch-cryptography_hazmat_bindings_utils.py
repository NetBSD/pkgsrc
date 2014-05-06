$NetBSD: patch-cryptography_hazmat_bindings_utils.py,v 1.2 2014/05/06 10:30:54 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- cryptography/hazmat/bindings/utils.py.orig	2014-05-03 14:19:18.000000000 +0000
+++ cryptography/hazmat/bindings/utils.py
@@ -73,7 +73,7 @@ def build_ffi(module_prefix, modules, pr
     )
     lib = ffi.verify(
         source=source,
-        modulename=_create_modulename(cdef_sources, source, sys.version),
+        modulename=module_name,
         libraries=libraries,
         ext_package="cryptography",
         extra_compile_args=extra_compile_args,
