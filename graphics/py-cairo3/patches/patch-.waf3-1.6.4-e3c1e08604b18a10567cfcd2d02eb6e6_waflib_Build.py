$NetBSD: patch-.waf3-1.6.4-e3c1e08604b18a10567cfcd2d02eb6e6_waflib_Build.py,v 1.1 2015/12/12 07:42:26 wiz Exp $

--- .waf3-1.6.4-e3c1e08604b18a10567cfcd2d02eb6e6/waflib/Build.py.orig	2011-03-29 14:52:54.000000000 +0000
+++ .waf3-1.6.4-e3c1e08604b18a10567cfcd2d02eb6e6/waflib/Build.py
@@ -151,6 +151,7 @@ class BuildContext(Context.Context):
 				f.close()
 		self.init_dirs()
 	def store(self):
+		return
 		data={}
 		for x in SAVED_ATTRS:
 			data[x]=getattr(self,x)
