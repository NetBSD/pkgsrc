$NetBSD: patch-setup.py,v 1.1 2019/05/29 20:13:09 adam Exp $

Do not require setuptools-git for building.

--- setup.py.orig	2019-03-10 15:33:57.000000000 +0000
+++ setup.py
@@ -14,7 +14,7 @@ tests_require = ['pytest>=2.3', 'tox', '
 if sys.version_info == (2, 7):
     tests_require.append('mock')
 
-setup_requires = ['setuptools', 'setuptools-git >= 0.3']
+setup_requires = ['setuptools']
 if sys.version_info >= (3, 5):
     setup_requires.append('wheel >= 0.25.0')  # earlier wheels fail in 3.5
 else:
