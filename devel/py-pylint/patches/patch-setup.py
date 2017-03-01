$NetBSD: patch-setup.py,v 1.1 2017/03/01 13:08:44 fhajny Exp $

Add PYVERSSUFFIX to scripts.

--- setup.py.orig	2017-01-22 13:12:37.000000000 +0000
+++ setup.py
@@ -140,11 +140,11 @@ def install(**kwargs):
             kwargs['install_requires'] = install_requires
             kwargs['dependency_links'] = dependency_links
         kwargs['entry_points'] = {'console_scripts': [
-            'pylint = pylint:run_pylint',
-            'pylint-gui = pylint:run_pylint_gui',
-            'epylint = pylint:run_epylint',
-            'pyreverse = pylint:run_pyreverse',
-            'symilar = pylint:run_symilar',
+            'pylint' + sys.version[0:3] + ' = pylint:run_pylint',
+            'pylint-gui' + sys.version[0:3] + ' = pylint:run_pylint_gui',
+            'epylint' + sys.version[0:3] + ' = pylint:run_epylint',
+            'pyreverse' + sys.version[0:3] + ' = pylint:run_pyreverse',
+            'symilar' + sys.version[0:3] + ' = pylint:run_symilar',
         ]}
     kwargs['packages'] = packages
     cmdclass = {'install_lib': MyInstallLib,
