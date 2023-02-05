$NetBSD: patch-python_mozbuild_mozbuild_makeutil.py,v 1.1 2023/02/05 08:32:24 he Exp $

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
