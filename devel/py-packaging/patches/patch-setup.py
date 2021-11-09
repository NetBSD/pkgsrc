$NetBSD: patch-setup.py,v 1.1 2021/11/09 20:35:14 wiz Exp $

Let pkgsrc handle version requirements.

--- setup.py.orig	2021-10-29 11:19:27.000000000 +0000
+++ setup.py
@@ -48,7 +48,7 @@ setup(
     author=about["__author__"],
     author_email=about["__email__"],
     python_requires=">=3.6",
-    install_requires=["pyparsing>=2.0.2,<3"],  # Needed to avoid issue #91
+    install_requires=["pyparsing"],
     classifiers=[
         "Development Status :: 5 - Production/Stable",
         "Intended Audience :: Developers",
