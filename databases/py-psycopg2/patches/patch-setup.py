$NetBSD: patch-setup.py,v 1.1 2018/07/03 03:57:16 adam Exp $

Do not install tests.

--- setup.py.orig	2018-06-29 10:27:08.000000000 +0000
+++ setup.py
@@ -675,7 +675,7 @@ setup(name="psycopg2",
       classifiers=[x for x in classifiers.split("\n") if x],
       data_files=data_files,
       package_dir={'psycopg2': 'lib', 'psycopg2.tests': 'tests'},
-      packages=['psycopg2', 'psycopg2.tests'],
+      packages=['psycopg2'],
       cmdclass={
           'build_ext': psycopg_build_ext,
           'build_py': build_py, },
