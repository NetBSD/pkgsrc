$NetBSD: patch-setup.py,v 1.1 2020/05/31 20:49:33 joerg Exp $

--- setup.py.orig	2020-05-31 18:05:52.507238288 +0000
+++ setup.py
@@ -1,10 +1,11 @@
+import sys
 from setuptools import setup
 
 setup(
     name='unicode-slugify',
     version='0.1.3',
     description='A slug generator that turns strings into unicode slugs.',
-    long_description=open('README.md').read(),
+    long_description=open('README.md', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read(),
     author='Jeff Balogh, Dave Dash',
     author_email='jbalogh@mozilla.com, dd@mozilla.com',
     url='http://github.com/mozilla/unicode-slugify',
