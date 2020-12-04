$NetBSD: patch-setup.py,v 1.2 2020/12/04 16:46:59 adam Exp $

Do not install data files.

--- setup.py.orig	2020-09-29 12:26:40.000000000 +0000
+++ setup.py
@@ -70,15 +70,6 @@ setup(
     license=LICENSE,
     packages=packages,
     include_package_data=True,
-    data_files=[
-        ('lib/site-packages/pygls', [
-            './CHANGELOG.md',
-            './LICENSE.txt',
-            './README.md',
-            'ThirdPartyNotices.txt',
-            './pygls/py.typed'
-        ])
-    ],
     zip_safe=False,
     install_requires=[],
     extras_require={
