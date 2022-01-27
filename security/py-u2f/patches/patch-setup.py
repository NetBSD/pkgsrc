$NetBSD: patch-setup.py,v 1.1 2022/01/27 10:39:35 wiz Exp $

--- setup.py.orig	2020-10-30 20:02:44.000000000 +0000
+++ setup.py
@@ -40,7 +40,6 @@ setuptools.setup(
         'six',
     ],
     tests_require=[
-        'unittest2>=0.5.1',
         'pyfakefs>=2.4',
         'mock>=1.0.1',
     ],
