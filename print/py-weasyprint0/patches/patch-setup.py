$NetBSD: patch-setup.py,v 1.4 2022/11/30 09:24:13 adam Exp $

Adjust script path to allow multiple Python version installs.

Do not require pytest-flake8 and pytest-isort as PkgSrc does have Python 2.7
versions anymore.

--- setup.py.orig	2018-03-27 20:48:21.000000000 +0000
+++ setup.py
@@ -75,15 +75,15 @@ setup(
     setup_requires=pytest_runner,
     test_suite='weasyprint.tests',
     tests_require=[
-        'pytest-runner', 'pytest-cov', 'pytest-flake8', 'pytest-isort'],
+        'pytest-runner', 'pytest-cov'],
     extras_require={
         'test': [
-            'pytest-runner', 'pytest-cov', 'pytest-flake8', 'pytest-isort'],
+            'pytest-runner', 'pytest-cov'],
         ':python_version < "3.0"': ['CairoSVG >= 1.0.20, < 2.0.0'],
         ':python_version >= "3.0"': ['CairoSVG >= 1.0.20']},
     entry_points={
         'console_scripts': [
-            'weasyprint = weasyprint.__main__:main',
+            'weasyprint%s = weasyprint.__main__:main' % sys.version[0:3],
         ],
     },
 )
