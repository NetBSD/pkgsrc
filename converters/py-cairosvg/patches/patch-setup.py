$NetBSD: patch-setup.py,v 1.1 2017/08/25 20:01:34 joerg Exp $

--- setup.py.orig	2017-08-25 16:01:40.820727909 +0000
+++ setup.py
@@ -21,7 +21,7 @@ from os import path
 from setuptools import setup
 
 init_path = path.join(path.dirname(__file__), 'cairosvg', '__init__.py')
-with open(init_path, 'r', encoding='utf-8') as fd:
+with open(init_path, 'r') as fd:
     version = re.search("__version__ = '([^']+)'", fd.read().strip()).group(1)
 
 needs_pytest = {'pytest', 'test', 'ptr'}.intersection(sys.argv)
