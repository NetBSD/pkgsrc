$NetBSD: patch-setup.py,v 1.3 2023/07/13 07:30:18 adam Exp $

Replace pycryptodomex with pycryptodome.

--- setup.py.orig	2021-01-22 15:01:09.000000000 +0000
+++ setup.py
@@ -46,7 +46,7 @@ setup(
         'setuptools',
         'stem>=1.8',
         'PyYAML>=4.2b1',
-        'pycryptodomex',
+        'pycryptodome',
         'future>=0.14.0',
         'setproctitle',
         'cryptography>=2.5',
