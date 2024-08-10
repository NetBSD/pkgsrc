$NetBSD: patch-common_setup.py,v 1.2 2024/08/10 06:24:24 wiz Exp $

Fix build with latest setuptools.
Do not depend on setuptools-git.

--- common_setup.py.orig	2019-05-28 06:32:17.000000000 +0000
+++ common_setup.py
@@ -38,7 +38,6 @@ class EggInfo(EggInfoCommand):
     def run(self):
         if self.distribution.extras_require is None:
             self.distribution.extras_require = {}
-        self.distribution.extras_require['tests'] = self.distribution.tests_require
         EggInfoCommand.run(self)
 
 
@@ -72,6 +71,5 @@ def common_setup(src_dir):
             license='MIT license',
             platforms=['unix', 'linux'],
             cmdclass={'test': PyTest, 'egg_info': EggInfo},
-            setup_requires=['setuptools-git'],
             include_package_data=True
             )
