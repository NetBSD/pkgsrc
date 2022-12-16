$NetBSD: patch-setup.py,v 1.1 2022/12/16 19:21:41 wiz Exp $

Not really needed.

--- setup.py.orig	2017-02-17 11:45:57.000000000 +0000
+++ setup.py
@@ -34,7 +34,6 @@ setup(
     tests_require=[
         'mock>=1.0.1',
         'nose>=1.3.6',
-        'nose-progressive>=1.5.1',
         'Pillow',
     ],
     test_suite='nose.collector',
