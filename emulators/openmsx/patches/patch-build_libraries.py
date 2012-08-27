$NetBSD: patch-build_libraries.py,v 1.1 2012/08/27 13:27:33 marino Exp $

The library check script is making assumptions about program locations.
The secret is define distroRoot as "None" so that no absolute path is
prepended on the binary.  

freetype-config is tricky because on NetBSD with native X11, it will
not be found at $PREFIX, but rather a X11 path.  The wrappers handle
this so use distroRoot=None to let configure search for freetype-config
and find it in the wrapper directories.

--- build/libraries.py.orig	2012-08-12 12:29:37.000000000 +0000
+++ build/libraries.py
@@ -168,10 +168,8 @@ class FreeType(Library):
 
 	@classmethod
 	def getConfigScript(cls, platform, linkStatic, distroRoot):
-		if platform in ('netbsd', 'openbsd'):
-			if distroRoot == '/usr/local':
-				# FreeType is located in the X11 tree, not the ports tree.
-				distroRoot = '/usr/X11R6'
+		# let pkgsrc wrappers handle this
+		distroRoot = None
 		return super(FreeType, cls).getConfigScript(
 			platform, linkStatic, distroRoot
 			)
