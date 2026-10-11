$NetBSD: patch-waflib_ConfigSet.py,v 1.1 2026/10/11 07:51:10 adam Exp $

Allow building with Python 3.11+.

--- waflib/ConfigSet.py.orig	2026-10-11 07:39:17.319048166 +0000
+++ waflib/ConfigSet.py
@@ -146,7 +146,7 @@ class ConfigSet(object):
 		Utils.writef(filename,''.join(buf))
 	def load(self,filename):
 		tbl=self.table
-		code=Utils.readf(filename,m='rU')
+		code=Utils.readf(filename,m='r')
 		for m in re_imp.finditer(code):
 			g=m.group
 			tbl[g(2)]=eval(g(3))
