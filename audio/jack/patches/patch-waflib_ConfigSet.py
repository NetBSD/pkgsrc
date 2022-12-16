$NetBSD: patch-waflib_ConfigSet.py,v 1.1 2022/12/16 07:36:41 wiz Exp $

Fix build with Python 3.11.
https://github.com/jackaudio/jack2/issues/898

--- waflib/ConfigSet.py.orig	2021-07-15 06:18:26.000000000 +0000
+++ waflib/ConfigSet.py
@@ -312,7 +312,7 @@ class ConfigSet(object):
 		:type filename: string
 		"""
 		tbl = self.table
-		code = Utils.readf(filename, m='rU')
+		code = Utils.readf(filename, m='r')
 		for m in re_imp.finditer(code):
 			g = m.group
 			tbl[g(2)] = eval(g(3))
