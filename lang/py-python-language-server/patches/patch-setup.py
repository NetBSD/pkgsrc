$NetBSD: patch-setup.py,v 1.1 2020/05/18 13:36:49 wiz Exp $

Accept any ujson.

--- setup.py.orig	2020-05-13 20:39:42.000000000 +0000
+++ setup.py
@@ -38,7 +38,7 @@ setup(
         'jedi>=0.17.0,<0.18.0',
         'python-jsonrpc-server>=0.3.2',
         'pluggy',
-        'ujson<=1.35; platform_system!="Windows"'
+        'ujson'
     ],
 
     # List additional groups of dependencies here (e.g. development
