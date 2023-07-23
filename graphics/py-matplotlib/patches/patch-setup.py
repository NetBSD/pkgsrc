$NetBSD: patch-setup.py,v 1.6 2023/07/23 14:43:02 bacon Exp $

# Hack to allow apps to run despite known issues
# Remove this patch when the upstream issue is fixed
# https://github.com/matplotlib/matplotlib/issues/26152

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
