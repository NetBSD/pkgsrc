$NetBSD: patch-setup.py,v 1.1 2019/09/09 07:09:47 maya Exp $

--- setup.py.orig	2010-04-10 17:41:18.000000000 +0000
+++ setup.py
@@ -2,5 +2,5 @@
 from distutils.core import setup, Extension
 
-module1 = Extension('sysctlmodule',
+module1 = Extension('sysctl',
                     sources = ['sysctlmodule.c'])
 
