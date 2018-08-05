$NetBSD: patch-setup.py,v 1.3 2018/08/05 10:30:12 adam Exp $

Allow newer pytest.

--- setup.py.orig	2018-07-25 00:03:25.000000000 +0000
+++ setup.py
@@ -26,7 +26,7 @@ setup(
     },
     install_requires=[
         # NOTE: pytest 3.3 broke something, not sure what yet
-        "pytest>=3,<3.3",
+        "pytest>=3.4",
         # TODO: ditto; six is so widely used it's prob worth having a broad pin
         "six>=1,<2",
         # TODO: ditto again!
