$NetBSD: patch-testing_mozbase_manifestparser_manifestparser_filters.py,v 1.1 2024/08/16 10:20:40 nia Exp $

These python libraries were moved out of "collections" and their
original locations were deprecated.

--- testing/mozbase/manifestparser/manifestparser/filters.py.orig	2024-08-16 10:11:13.194233011 +0000
+++ testing/mozbase/manifestparser/manifestparser/filters.py
@@ -12,7 +12,8 @@ from __future__ import absolute_import
 
 import itertools
 import os
-from collections import defaultdict, MutableSequence
+from collections import defaultdict
+from collections.abc import MutableSequence
 
 import six
 from six import string_types
