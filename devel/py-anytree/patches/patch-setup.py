$NetBSD: patch-setup.py,v 1.1 2020/01/08 21:25:31 adam Exp $

Avoid files outside PYSITELIB.

--- setup.py.orig	2020-01-08 21:21:42.000000000 +0000
+++ setup.py
@@ -49,7 +49,6 @@ config['extras_require'] = {
 }
 config['tests_require'] = ['nose']
 config['test_suite'] = 'nose.collector'
-config['data_files'] = [('', ['LICENSE'])]
 
 # Get the long description from the README file
 here = path.abspath(path.dirname(__file__))
