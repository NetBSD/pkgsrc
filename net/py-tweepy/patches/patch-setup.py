$NetBSD: patch-setup.py,v 1.1 2020/02/24 00:02:59 joerg Exp $

Don't use obsolete parse_requirements.

--- setup.py.orig	2020-02-22 21:25:23.469977185 +0000
+++ setup.py
@@ -2,7 +2,6 @@
 #from distutils.core import setup
 import re, uuid
 from setuptools import setup, find_packages
-from pip.req import parse_requirements
 
 VERSIONFILE = "tweepy/__init__.py"
 ver_file = open(VERSIONFILE, "rt").read()
@@ -14,9 +13,6 @@ if mo:
 else:
     raise RuntimeError("Unable to find version string in %s." % (VERSIONFILE,))
 
-install_reqs = parse_requirements('requirements.txt', session=uuid.uuid1())
-reqs = [str(req.req) for req in install_reqs]
-
 setup(name="tweepy",
       version=version,
       description="Twitter library for python",
@@ -25,7 +21,6 @@ setup(name="tweepy",
       author_email="tweepy@googlegroups.com",
       url="http://github.com/tweepy/tweepy",
       packages=find_packages(exclude=['tests']),
-      install_requires=reqs,
       keywords="twitter library",
       classifiers=[
           'Development Status :: 4 - Beta',
