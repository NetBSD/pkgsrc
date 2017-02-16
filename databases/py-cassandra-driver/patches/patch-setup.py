$NetBSD: patch-setup.py,v 1.1 2017/02/16 10:43:12 fhajny Exp $

Backport a trunk commit to let us override the Cython version req.

--- setup.py.orig	2016-10-26 15:00:31.000000000 +0000
+++ setup.py
@@ -388,7 +388,11 @@ def run_setup(extensions):
         # 1.) build_ext eats errors at compile time, letting the install complete while producing useful feedback
         # 2.) there could be a case where the python environment has cython installed but the system doesn't have build tools
         if pre_build_check():
-            kw['setup_requires'] = ['Cython>=0.20,<0.25']
+            cython_dep = 'Cython>=0.20,<0.25'
+            user_specified_cython_version = os.environ.get('CASS_DRIVER_ALLOWED_CYTHON_VERSION')
+            if user_specified_cython_version is not None:
+                cython_dep = 'Cython==%s' % (user_specified_cython_version,)
+            kw['setup_requires'] = [cython_dep]
         else:
             sys.stderr.write("Bypassing Cython setup requirement\n")
 
