$NetBSD: patch-setup.py,v 1.1 2021/09/27 02:00:44 mef Exp $

py36 flags:
UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 1085: ordinal not in range(128)

--- setup.py.orig	2021-01-11 23:58:48.000000000 +0900
+++ setup.py	2021-09-27 10:51:25.778622523 +0900
@@ -2,6 +2,8 @@ from __future__ import absolute_import, 
 
 from os.path import dirname, join
 
+import sys
+
 try:
     from setuptools import setup
 except:
@@ -29,7 +31,7 @@ setup(
     maintainer_email='kbullock+mercurial@ringworld.org',
     url='http://foss.heptapod.net/mercurial/hg-git',
     description='push to and pull from a Git repository using Mercurial',
-    long_description=get_file("README.rst"),
+    long_description=''.join(open('README.rst', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).readlines()),
     keywords='hg git mercurial',
     license='GPLv2',
     packages=['hggit'],
