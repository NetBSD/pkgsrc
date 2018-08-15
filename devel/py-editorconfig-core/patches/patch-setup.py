$NetBSD: patch-setup.py,v 1.2 2018/08/15 11:23:08 adam Exp $

* remove non-versioned file. The console command for editorconfig-core 
  is in the editorconfig-core package. Removing this file removes the 
  conflict that this package would have with the editorconfig-core 
  package.

--- setup.py.orig	2018-04-17 03:59:54.000000000 +0000
+++ setup.py
@@ -11,11 +11,6 @@ setup(
     license='python',
     description='EditorConfig File Locator and Interpreter for Python',
     long_description=open('README.rst').read(),
-    entry_points = {
-        'console_scripts': [
-            'editorconfig = editorconfig.main:main',
-        ]
-    },
     classifiers=[
         'License :: OSI Approved :: Python Software Foundation License',
         'Operating System :: OS Independent',
