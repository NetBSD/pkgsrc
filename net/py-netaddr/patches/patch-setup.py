$NetBSD: patch-setup.py,v 1.3 2017/09/28 12:25:11 adam Exp $

Do not overwrite script's interpreter.

--- setup.py.orig	2017-01-11 23:42:52.000000000 +0000
+++ setup.py
@@ -176,7 +176,6 @@ def main():
         version=netaddr.__version__,
         options={
             'build_scripts': {
-                'executable': '/usr/bin/env python',
             },
         },
     )
