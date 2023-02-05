$NetBSD: patch-testing_mozbase_manifestparser_manifestparser_filters.py,v 1.1 2023/02/05 08:32:24 he Exp $

Adjust for python 3.10

--- testing/mozbase/manifestparser/manifestparser/filters.py.orig	2021-07-12 13:35:02.000000000 +0000
+++ testing/mozbase/manifestparser/manifestparser/filters.py
@@ -12,7 +12,8 @@ from __future__ import absolute_import
 
 import itertools
 import os
-from collections import defaultdict, MutableSequence
+from collections import defaultdict
+from collections.abc import MutableSequence
 
 import six
 from six import string_types
