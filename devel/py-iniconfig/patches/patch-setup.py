$NetBSD: patch-setup.py,v 1.1 2020/08/08 18:09:55 joerg Exp $

Add missing version number.

--- setup.py.orig	2020-08-08 17:30:18.066633508 +0000
+++ setup.py
@@ -14,6 +14,7 @@ def main():
         readme = fp.read()
     setup(
         name='iniconfig',
+        version='1.0.1',
         py_modules=['iniconfig'],
         description='iniconfig: brain-dead simple config-ini parsing',
         long_description=readme,
