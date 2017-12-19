$NetBSD: patch-setup.py,v 1.1 2017/12/19 12:22:20 adam Exp $

Explicitly define dependencies; the files are missing.

--- setup.py.orig	2017-11-06 09:20:43.000000000 +0000
+++ setup.py
@@ -5,8 +5,8 @@ long_description = None
 if exists("README.md"):
     long_description = open("README.md").read()
 
-install_reqs = [req for req in open(abspath(join(dirname(__file__), 'requirements.txt')))]
-tests_reqs = [req for req in open(abspath(join(dirname(__file__), 'test-requirements.txt')))]
+install_reqs = ['future']
+tests_reqs = []
 
 setup(
   name="mpegdash",
