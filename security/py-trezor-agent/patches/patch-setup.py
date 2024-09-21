$NetBSD: patch-setup.py,v 1.1 2024/09/21 12:45:49 js Exp $

Relax dependencies.

--- setup.py.orig	2024-09-21 12:35:21.488137802 +0000
+++ setup.py
@@ -11,7 +11,7 @@ setup(
     scripts=['trezor_agent.py'],
     install_requires=[
         'libagent>=0.14.0',
-        'trezor[hidapi]>=0.13'
+        'trezor>=0.13'
     ],
     platforms=['POSIX'],
     classifiers=[
