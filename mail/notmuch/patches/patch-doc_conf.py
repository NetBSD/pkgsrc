$NetBSD: patch-doc_conf.py,v 1.1 2018/12/27 15:07:05 joerg Exp $

--- doc/conf.py.orig	2018-12-25 23:11:46.371067128 +0000
+++ doc/conf.py
@@ -17,7 +17,7 @@ copyright = u'2009-2018, Carl Worth and 
 location = os.path.dirname(__file__)
 
 for pathdir in ['.', '..']:
-    version_file = os.path.join(location,pathdir,'version')
+    version_file = os.path.join(location,pathdir,'version.txt')
     if os.path.exists(version_file):
         with open(version_file,'r') as infile:
             version=infile.read().replace('\n','')
