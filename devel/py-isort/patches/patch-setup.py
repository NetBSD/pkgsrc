$NetBSD: patch-setup.py,v 1.1 2017/02/28 20:54:09 fhajny Exp $

Use PYVERSSUFFIX with scripts.

--- setup.py.orig	2016-03-30 11:08:25.000000000 +0000
+++ setup.py
@@ -49,7 +49,7 @@ setup(name='isort',
       license="MIT",
       entry_points={
         'console_scripts': [
-            'isort = isort.main:main',
+            'isort' + sys.version[0:3] + ' = isort.main:main',
         ],
         'distutils.commands': ['isort = isort.main:ISortCommand'],
         'pylama.linter': ['isort = isort.pylama_isort:Linter'],
