$NetBSD: patch-setup.py,v 1.1 2013/09/08 16:33:56 ryoon Exp $

* Do not use setuptools bootstrap, use py-setuptools from pkgsrc.

--- setup.py.orig	2013-09-06 23:07:42.000000000 +0000
+++ setup.py
@@ -4,8 +4,8 @@
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
-from ez_setup import use_setuptools
-use_setuptools()
+#from ez_setup import use_setuptools
+#use_setuptools()
 from setuptools import setup
 
 setup(
