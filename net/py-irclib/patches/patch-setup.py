$NetBSD: patch-setup.py,v 1.1 2015/03/18 10:28:42 joerg Exp $

--- setup.py.orig	2015-03-17 23:03:00.000000000 +0000
+++ setup.py
@@ -33,9 +33,9 @@ setup_params = dict(
     ],
     setup_requires=[
         'hgtools>=5',
-        'pytest-runner',
     ],
     tests_require=[
+        'pytest-runner',
         'pytest',
         'mock',
     ],
