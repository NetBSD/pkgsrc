$NetBSD: patch-cryptography_hazmat_bindings_utils.py,v 1.1 2014/03/21 14:02:45 wiz Exp $

Fix soname so cffi doesn't invent one for each python version + platform.

--- cryptography/hazmat/bindings/utils.py.orig	2014-03-04 00:51:26.000000000 +0000
+++ cryptography/hazmat/bindings/utils.py
@@ -69,6 +69,7 @@ def build_ffi(module_prefix, modules, pr
             customizations
         ),
         libraries=libraries,
+        modulename=module_name,
         ext_package="cryptography",
     )
 
