$NetBSD: patch-BuildTools_SCons_Tools_qt4.py,v 1.1 2014/04/26 11:41:46 wiz Exp $

Handle NetBSD like Linux.

--- BuildTools/SCons/Tools/qt4.py.orig	2012-12-22 12:23:58.000000000 +0000
+++ BuildTools/SCons/Tools/qt4.py
@@ -448,7 +448,7 @@ def enable_modules(self, modules, debug=
 		except: pass
 	debugSuffix = ''
 
-	if sys.platform.startswith("linux") and not crosscompiling :
+	if (sys.platform.startswith("linux") or sys.platform.startswith("netbsd")) and not crosscompiling :
 		if debug : debugSuffix = '_debug'
 		self.AppendUnique(CPPPATH=[os.path.join("$QTDIR","include", "phonon")])
 		for module in modules :
