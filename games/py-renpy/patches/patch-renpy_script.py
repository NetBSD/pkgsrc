$NetBSD: patch-renpy_script.py,v 1.1 2023/03/10 21:14:39 ryoon Exp $

--- renpy/script.py.orig	2022-09-08 03:49:02.963533200 +0000
+++ renpy/script.py
@@ -645,21 +645,6 @@ class Script(object):
 
             pickle_data_after_static_transforms = dumps((data, stmts))
 
-            if not renpy.macapp:
-                try:
-                    with open(rpycfn, "wb") as f:
-                        self.write_rpyc_header(f)
-                        self.write_rpyc_data(f, 1, pickle_data_before_static_transforms)
-                        self.write_rpyc_data(f, 2, pickle_data_after_static_transforms)
-
-                        with open(fullfn, "rb") as fullf:
-                            rpydigest = hashlib.md5(fullf.read()).digest()
-
-                        self.write_rpyc_md5(f, rpydigest)
-                except Exception:
-                    import traceback
-                    traceback.print_exc()
-
             self.loaded_rpy = True
 
         elif fn.endswith(".rpyc") or fn.endswith(".rpymc"):
