$NetBSD: patch-setup.py,v 1.1 2017/04/14 13:08:16 leot Exp $

Avoid UnicodeDecodeError with Python 3 due offending characters in
HISTORY.rst.

--- setup.py.orig	2016-12-23 17:15:38.000000000 +0000
+++ setup.py
@@ -31,7 +31,7 @@ setup(
     name='hpack',
     version=version,
     description='Pure-Python HPACK header compression',
-    long_description=open('README.rst').read() + '\n\n' + open('HISTORY.rst').read(),
+    long_description=open('README.rst').read(),
     author='Cory Benfield',
     author_email='cory@lukasa.co.uk',
     url='http://hyper.rtfd.org',
