$NetBSD: patch-setup.py,v 1.2 2020/05/12 18:40:35 adam Exp $

Replace pycrypto with pycryptodome.

--- setup.py.orig	2020-04-14 22:49:04.000000000 +0000
+++ setup.py
@@ -46,7 +46,7 @@ setup(
         'setuptools',
         'stem>=1.8',
         'PyYAML>=4.2b1',
-        'pycrypto>=2.6.1',
+        'pycryptodome',
         'future>=0.14.0',
         'setproctitle',
         'cryptography>=2.5',
