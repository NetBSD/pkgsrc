$NetBSD: patch-setup.py,v 1.1 2024/10/17 00:51:49 gutteridge Exp $

Install the man page.
https://github.com/secdev/scapy/pull/4569/commits/4f33e4d381957e9237402ecc8597d4de23f54b76

--- setup.py.orig	2024-09-28 13:11:32.000000000 +0000
+++ setup.py
@@ -83,6 +83,7 @@ class BuildPy(build_py):
 
 setup(
     cmdclass={'sdist': SDist, 'build_py': BuildPy},
+    data_files=[('share/man/man1', ["doc/scapy.1"])],
     long_description=get_long_description(),
     long_description_content_type='text/markdown',
 )
