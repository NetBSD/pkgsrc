$NetBSD: patch-setup.py,v 1.1 2021/12/16 13:10:01 wiz Exp $

Compatibility with latest setuptools.

--- setup.py.orig	2018-02-25 16:27:09.000000000 +0000
+++ setup.py
@@ -100,8 +100,6 @@ setup(
             "pylint",
         ],
     },
-    # MAYBE-DISABLE: use_2to3
-    use_2to3= bool(python_version >= 3.0),
     license="BSD",
     classifiers=[
         "Development Status :: 4 - Beta",
