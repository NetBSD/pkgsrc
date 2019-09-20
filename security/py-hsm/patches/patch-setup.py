$NetBSD: patch-setup.py,v 1.1 2019/09/20 17:13:26 adam Exp $

Prefer py-cryptodome.

--- setup.py.orig	2019-09-20 17:03:05.000000000 +0000
+++ setup.py
@@ -71,7 +71,7 @@ setup(
     tests_require=[],
     install_requires=[
         'pyserial >= 2.3',
-        'pycrypto >= 2.1'
+        'pycryptodome'
     ],
     extras_require={
         'db': ['sqlalchemy'],
