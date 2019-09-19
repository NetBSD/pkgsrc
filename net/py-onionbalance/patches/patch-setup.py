$NetBSD: patch-setup.py,v 1.1 2019/09/19 21:25:52 adam Exp $

Replace pycrypto with pycryptodome.

--- setup.py.orig	2019-09-19 21:01:51.000000000 +0000
+++ setup.py
@@ -43,7 +43,7 @@ setup(
         'setuptools',
         'stem>=1.4.0-dev',
         'PyYAML>=3.11',
-        'pycrypto>=2.6.1',
+        'pycryptodome',
         'future>=0.14.0',
         'setproctitle',
         ],
