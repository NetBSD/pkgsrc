$NetBSD: patch-setup.py,v 1.1 2020/08/27 12:28:06 joerg Exp $

--- setup.py.orig	2020-08-26 11:55:49.857831827 +0000
+++ setup.py
@@ -57,7 +57,7 @@ setup(
     name="zfec",
     version=versioneer.get_version(),
     description="An efficient, portable erasure coding tool",
-    long_description=open('README.rst', 'rU').read(),
+    long_description=open('README.rst', 'rU', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read(),
     url="https://github.com/tahoe-lafs/zfec",
     install_requires=[
         "pyutil >= 3.0.0",
