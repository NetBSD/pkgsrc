$NetBSD: patch-src_cryptography_hazmat_bindings_utils.py,v 1.1 2015/01/03 16:00:55 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- src/cryptography/hazmat/bindings/utils.py.orig	2014-12-29 01:46:47.000000000 +0000
+++ src/cryptography/hazmat/bindings/utils.py
@@ -93,6 +93,7 @@ def build_ffi_for_binding(module_prefix,
         cdef_source="\n".join(types + functions + macros),
         verify_source=verify_source,
         libraries=libraries,
+        module_name=module_name,
         extra_compile_args=extra_compile_args,
         extra_link_args=extra_link_args,
     )
@@ -100,7 +101,7 @@ def build_ffi_for_binding(module_prefix,
     return ffi
 
 
-def build_ffi(cdef_source, verify_source, libraries=[], extra_compile_args=[],
+def build_ffi(cdef_source, verify_source, module_name, libraries=[], extra_compile_args=[],
               extra_link_args=[]):
     ffi = FFI()
     ffi.cdef(cdef_source)
@@ -109,7 +110,7 @@ def build_ffi(cdef_source, verify_source
         ffi,
         verify_source,
         tmpdir='',
-        modulename=_create_modulename(cdef_source, verify_source, sys.version),
+        modulename=module_name,
         libraries=libraries,
         ext_package="cryptography",
         extra_compile_args=extra_compile_args,
