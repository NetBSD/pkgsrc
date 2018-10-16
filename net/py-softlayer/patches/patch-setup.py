$NetBSD: patch-setup.py,v 1.2 2018/10/16 13:49:53 adam Exp $

Relax requirements.

--- setup.py.orig	2018-10-16 13:35:40.000000000 +0000
+++ setup.py
@@ -32,7 +32,7 @@ setup(
     install_requires=[
         'six >= 1.7.0',
         'ptable >= 0.9.2',
-        'click >= 5, < 7',
+        'click >= 5',
         'requests >= 2.18.4',
         'prompt_toolkit >= 0.53',
         'pygments >= 2.0.0',
