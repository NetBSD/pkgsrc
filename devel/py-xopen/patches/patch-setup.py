$NetBSD: patch-setup.py,v 1.1 2019/01/09 10:49:28 adam Exp $

Replace non-ASCII character.

--- setup.py.orig	2019-01-09 10:39:25.000000000 +0000
+++ setup.py
@@ -11,7 +11,7 @@ with open('README.rst') as f:
 setup(
     name='xopen',
     use_scm_version=True,
-    setup_requires=['setuptools_scm'],  # Support pip versions that don’t know about pyproject.toml
+    setup_requires=['setuptools_scm'],  # Support pip versions that don't know about pyproject.toml
     author='Marcel Martin',
     author_email='mail@marcelm.net',
     url='https://github.com/marcelm/xopen/',
