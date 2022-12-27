$NetBSD: patch-python_mozbuild_mozbuild_makeutil.py,v 1.1 2022/12/27 20:08:45 abs Exp $

Adjust for python 3.10

--- python/mozbuild/mozbuild/makeutil.py.orig	2021-07-12 13:35:01.000000000 +0000
+++ python/mozbuild/mozbuild/makeutil.py
@@ -7,7 +7,7 @@ from __future__ import absolute_import, 
 import os
 import re
 import six
-from collections import Iterable
+from collections.abc import Iterable
 
 
 class Makefile(object):
