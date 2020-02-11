$NetBSD: patch-setup.py,v 1.1 2020/02/11 17:02:11 adam Exp $

Do not install README.rst.

--- setup.py.orig	2020-02-11 16:56:13.000000000 +0000
+++ setup.py
@@ -40,7 +40,6 @@ test_requires = [
 setup(
     name='Wand',
     packages=['wand', 'wand.cdefs'],
-    data_files=[('', ['README.rst'])],
     version=VERSION,
     description='Ctypes-based simple MagickWand API binding for Python',
     long_description=readme(),
