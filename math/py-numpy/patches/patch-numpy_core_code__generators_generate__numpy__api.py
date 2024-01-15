$NetBSD: patch-numpy_core_code__generators_generate__numpy__api.py,v 1.1 2024/01/15 17:50:34 wiz Exp $

Do not call distutils code, for Python 3.12 compat.

--- numpy/core/code_generators/generate_numpy_api.py.orig	2024-01-15 17:44:12.338306195 +0000
+++ numpy/core/code_generators/generate_numpy_api.py
@@ -149,10 +149,7 @@ def generate_api(output_dir, force=False
 
     sources = numpy_api.multiarray_api
 
-    if (not force and not genapi.should_rebuild(targets, [numpy_api.__file__, __file__])):
-        return targets
-    else:
-        do_generate_api(targets, sources)
+    do_generate_api(targets, sources)
 
     return targets
 
