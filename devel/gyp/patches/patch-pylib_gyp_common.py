$NetBSD: patch-pylib_gyp_common.py,v 1.5 2022/01/27 18:42:15 wiz Exp $

* Python 3.10 support
* Add NetBSD support

--- pylib/gyp/common.py.orig	2022-01-27 18:36:11.000000000 +0000
+++ pylib/gyp/common.py
@@ -4,7 +4,7 @@
 
 from __future__ import with_statement
 
-import collections
+import collections.abc as collections
 import errno
 import filecmp
 import os.path
@@ -445,6 +445,7 @@ def CopyTool(flavor, out_path, generator
   prefix = {
       'aix': 'flock',
       'solaris': 'flock',
+      'netbsd': 'flock',
       'mac': 'mac',
       'win': 'win'
       }.get(flavor, None)
