$NetBSD: patch-pylib_gyp_common.py,v 1.6 2026/02/04 00:06:54 wiz Exp $

* Add NetBSD support

--- pylib/gyp/common.py.orig	2022-01-27 18:36:11.000000000 +0000
+++ pylib/gyp/common.py
@@ -445,6 +445,7 @@ def CopyTool(flavor, out_path, generator
   prefix = {
       'aix': 'flock',
       'solaris': 'flock',
+      'netbsd': 'flock',
       'mac': 'mac',
       'win': 'win'
       }.get(flavor, None)
