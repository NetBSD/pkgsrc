$NetBSD: patch-ArgParser.py,v 1.1 2012/04/11 19:32:17 darcy Exp $

Set up BSD paths.

--- share/gitso/ArgsParser.py.orig	2012-04-11 18:44:23.000000000 +0000
+++ share/gitso/ArgsParser.py
@@ -46,6 +46,10 @@ class ArgsParser:
 		if sys.platform.find('linux') != -1:
 			self.paths['main'] = os.path.join(sys.path[0], '..', 'share', 'gitso')
 			self.paths['copyright'] = os.path.join(sys.path[0], '..', 'share', 'doc', 'gitso', 'COPYING')
+		if sys.platform.find('bsd') != -1:
+			import gitso
+			self.paths['main'] = gitso.__path__[0]
+			self.paths['copyright'] = os.path.join(gitso.__path__[0], 'COPYING')
 		elif sys.platform == "darwin":
 			self.paths['main'] = sys.path[0]
 			self.paths['copyright'] = os.path.join(sys.path[0], 'COPYING')
