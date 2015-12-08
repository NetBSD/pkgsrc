$NetBSD: patch-setup.py,v 1.2 2015/12/08 14:12:03 nonaka Exp $

--- setup.py.orig	2015-11-16 13:32:05.000000000 +0900
+++ setup.py	2015-12-08 22:57:38.000000000 +0900
@@ -2,6 +2,7 @@
 
 import os
 import sys
+import setuptools
 from distutils.core import setup, Extension
 
 
