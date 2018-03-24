$NetBSD: patch-common_setup.py,v 1.1 2018/03/24 07:14:59 adam Exp $

Do not depend on setuptools-git.

--- common_setup.py.orig	2018-03-24 07:08:04.000000000 +0000
+++ common_setup.py
@@ -72,6 +72,5 @@ def common_setup(src_dir):
             license='MIT license',
             platforms=['unix', 'linux'],
             cmdclass={'test': PyTest, 'egg_info': EggInfo},
-            setup_requires=['setuptools-git'],
             include_package_data=True
             )
