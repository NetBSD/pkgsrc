$NetBSD: patch-setup.py,v 1.1 2021/12/16 14:48:11 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2016-12-13 17:02:57.000000000 +0000
+++ setup.py
@@ -115,5 +115,4 @@ setup(name=name,
     test_suite='trytond.tests',
     test_loader='trytond.test_loader:Loader',
     tests_require=['mock'],
-    use_2to3=True,
     )
