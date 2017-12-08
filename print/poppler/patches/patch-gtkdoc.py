$NetBSD: patch-gtkdoc.py,v 1.1 2017/12/08 07:48:11 spz Exp $

--- gtkdoc.py.orig	2017-11-12 18:14:32.000000000 +0000
+++ gtkdoc.py
@@ -223,6 +223,9 @@ class GTKDoc(object):
             return
 
         def copy_file_replacing_existing(src, dest):
+            if src == dest:
+		self.logger.debug('copy_file_replacing_existing not copying to itself: %s', src)
+		return
             if os.path.isdir(src):
                 self.logger.debug('skipped directory %s',  src)
                 return
