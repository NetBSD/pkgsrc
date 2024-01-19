$NetBSD: patch-numpy_core_code__generators_generate__ufunc__api.py,v 1.1.2.2 2024/01/19 20:15:33 bsiegert Exp $

Do not call distutils code, for Python 3.12 compat.

--- numpy/core/code_generators/generate_ufunc_api.py.orig	2024-01-15 17:44:22.009704598 +0000
+++ numpy/core/code_generators/generate_ufunc_api.py
@@ -126,10 +126,7 @@ def generate_api(output_dir, force=False
 
     sources = ['ufunc_api_order.txt']
 
-    if (not force and not genapi.should_rebuild(targets, sources + [__file__])):
-        return targets
-    else:
-        do_generate_api(targets, sources)
+    do_generate_api(targets, sources)
 
     return targets
 
