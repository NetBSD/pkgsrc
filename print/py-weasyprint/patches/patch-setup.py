$NetBSD: patch-setup.py,v 1.2 2017/08/01 15:36:26 kleink Exp $

Adjust script path to allow multiple Python version installs.

--- setup.py.orig	2017-06-22 16:31:14.000000000 +0000
+++ setup.py
@@ -87,7 +87,7 @@ setup(
         "pytest-runner", "pytest-cov", "pytest-flake8", "pytest-isort"]},
     entry_points={
         'console_scripts': [
-            'weasyprint = weasyprint.__main__:main',
+            'weasyprint%s = weasyprint.__main__:main' % sys.version[0:3],
         ],
     },
 )
