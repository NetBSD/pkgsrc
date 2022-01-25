$NetBSD: patch-setup.py,v 1.1 2022/01/25 12:59:39 ryoon Exp $

Avoid locale-based exceptions when building for Python 3.6.

--- setup.py.orig	2021-08-25 01:40:01.730815286 +0000
+++ setup.py
@@ -4,6 +4,9 @@ import os
 from codecs import open
 
 from setuptools import setup
+import locale
+
+locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
 
 here = os.path.abspath(os.path.dirname(__file__))
 
