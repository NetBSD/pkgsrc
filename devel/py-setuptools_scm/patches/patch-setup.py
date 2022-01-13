$NetBSD: patch-setup.py,v 1.1 2022/01/13 21:03:51 wiz Exp $

Do not put tomli dependency in requires.txt.
tomli is not found by setuptools, since it's a wheel, not an egg.

--- setup.py.orig	2021-09-11 19:26:20.000000000 +0000
+++ setup.py
@@ -61,7 +61,6 @@ if __name__ == "__main__":
         extras_require={
             "toml": [
                 "setuptools>=42",
-                "tomli>=1.0.0",
             ],
         },
         cmdclass={"bdist_egg": bdist_egg},
