$NetBSD: patch-tests_run-tests.py,v 1.3 2023/04/12 10:39:06 wiz Exp $

https://bz.mercurial-scm.org/show_bug.cgi?id=6805
https://www.mercurial-scm.org/repo/hg/rev/787e7caf887a

--- tests/run-tests.py.orig	2023-03-23 23:11:29.000000000 +0000
+++ tests/run-tests.py
@@ -54,7 +54,6 @@ import functools
 import json
 import multiprocessing
 import os
-import packaging.version as version
 import platform
 import queue
 import random
@@ -794,9 +793,7 @@ def parseargs(args, parser):
         try:
             import coverage
 
-            covver = version.Version(coverage.__version__)
-            if covver < version.Version("3.3"):
-                parser.error('coverage options require coverage 3.3 or later')
+            coverage.__version__  # silence unused import warning
         except ImportError:
             parser.error('coverage options now require the coverage package')
 
