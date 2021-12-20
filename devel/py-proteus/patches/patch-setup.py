$NetBSD: patch-setup.py,v 1.1 2021/12/20 22:06:16 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2016-11-05 18:56:58.000000000 +0000
+++ setup.py
@@ -87,5 +87,4 @@ setup(name=name,
     test_suite='proteus.tests',
     tests_require=[get_require_version('trytond'),
         get_require_version('trytond_party')],
-    use_2to3=True,
     )
