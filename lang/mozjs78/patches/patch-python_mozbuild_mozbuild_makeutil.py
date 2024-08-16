$NetBSD: patch-python_mozbuild_mozbuild_makeutil.py,v 1.1 2024/08/16 10:20:40 nia Exp $

These python libraries were moved out of "collections" and their
original locations were deprecated.

--- python/mozbuild/mozbuild/makeutil.py.orig	2024-08-16 10:12:38.748775642 +0000
+++ python/mozbuild/mozbuild/makeutil.py
@@ -7,7 +7,7 @@ from __future__ import absolute_import, 
 import os
 import re
 import six
-from collections import Iterable
+from collections.abc import Iterable
 
 
 class Makefile(object):
