$NetBSD: patch-setup.py,v 1.2 2020/12/19 15:28:05 gdt Exp $

\todo Document this patch.
\todo File this patch upstream.

--- setup.py.orig	2020-09-18 02:16:19.000000000 +0000
+++ setup.py
@@ -57,7 +57,7 @@ setup(
     name="zfec",
     version=versioneer.get_version(),
     description="An efficient, portable erasure coding tool",
-    long_description=open('README.rst', 'r').read(),
+    long_description=open('README.rst', 'rU', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read(),
     url="https://github.com/tahoe-lafs/zfec",
     install_requires=[
         "argparse >= 0.8",
