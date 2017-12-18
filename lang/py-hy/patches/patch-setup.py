$NetBSD: patch-setup.py,v 1.1 2017/12/18 12:48:46 adam Exp $

Do not install get_version.py; it is needed only for setup.py.

--- setup.py.orig	2017-12-18 08:29:33.000000000 +0000
+++ setup.py
@@ -57,9 +57,6 @@ setup(
         'hy.core': ['*.hy', '__pycache__/*'],
         'hy.extra': ['*.hy', '__pycache__/*'],
     },
-    data_files=[
-        ('get_version', ['get_version.py'])
-    ],
     author="Paul Tagliamonte",
     author_email="tag@pault.ag",
     long_description=long_description,
