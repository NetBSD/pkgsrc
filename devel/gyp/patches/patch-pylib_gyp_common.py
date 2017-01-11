$NetBSD: patch-pylib_gyp_common.py,v 1.4 2017/01/11 14:47:51 wiz Exp $

* Add NetBSD support

--- pylib/gyp/common.py.orig	2017-01-11 14:31:33.000000000 +0000
+++ pylib/gyp/common.py
@@ -441,6 +441,7 @@ def CopyTool(flavor, out_path, generator
   prefix = {
       'aix': 'flock',
       'solaris': 'flock',
+      'netbsd': 'flock',
       'mac': 'mac',
       'win': 'win'
       }.get(flavor, None)
