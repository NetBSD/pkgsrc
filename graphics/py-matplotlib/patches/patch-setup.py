$NetBSD: patch-setup.py,v 1.5 2023/07/20 14:46:43 bacon Exp $

# Hack to allow apps to run despite known issues

--- setup.py.orig	2023-07-20 13:08:02.696854685 +0000
+++ setup.py
@@ -325,7 +325,7 @@ setup(  # Finally, pass this all along t
         "numpy>=1.20",
         "packaging>=20.0",
         "pillow>=6.2.0",
-        "pyparsing>=2.3.1,<3.1",
+        "pyparsing>=2.3.1",
         "python-dateutil>=2.7",
     ] + (
         # Installing from a git checkout that is not producing a wheel.
