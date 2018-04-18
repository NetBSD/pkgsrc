$NetBSD: patch-setup.py,v 1.2 2018/04/18 07:18:21 adam Exp $

Allow newer pytest.

--- setup.py.orig	2018-04-18 07:14:04.000000000 +0000
+++ setup.py
@@ -29,7 +29,7 @@ setup(
 
     install_requires=[
         # NOTE: pytest 3.3 broke something, not sure what yet
-        'pytest>=3,<3.3',
+        'pytest>=3.4',
         # TODO: ditto; six is so widely used it's prob worth having a broad pin
         'six>=1,<2',
         # TODO: ditto again!
