$NetBSD: patch-setup.py,v 1.3 2022/11/26 19:53:38 adam Exp $

Do not install get_version.py; it is needed only for setup.py.

--- setup.py.orig	2022-08-30 17:28:07.000000000 +0000
+++ setup.py
@@ -60,7 +60,6 @@ setup(
     package_data={
         "": ["*.hy"],
     },
-    data_files=[("get_version", ["get_version.py"])],
     author="Paul Tagliamonte",
     author_email="tag@pault.ag",
     long_description=long_description,
