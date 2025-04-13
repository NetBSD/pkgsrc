$NetBSD: patch-setup.py,v 1.4 2025/04/13 08:05:55 wiz Exp $

Replace pycryptodomex with pycryptodome.

--- setup.py.orig	2025-04-09 15:31:17.000000000 +0000
+++ setup.py
@@ -47,7 +47,7 @@ setup(
         'setuptools',
         'stem>=1.8',
         'PyYAML>=4.2b1',
-        'pycryptodomex',
+        'pycryptodome',
         'setproctitle',
         'cryptography>=2.5',
     ],
