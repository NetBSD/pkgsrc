$NetBSD: patch-build_version.py,v 1.1 2012/08/26 09:07:23 marino Exp $

Bug caused subversion to run during the make process.  This patch is
proposed by upstream.

--- build/version.py.orig	2012-08-12 12:29:37.000000000 +0000
+++ build/version.py
@@ -50,6 +50,10 @@ def extractRevision():
 	global _cachedRevision
 	if _cachedRevision is not False:
 		return _cachedRevision
+	if releaseFlag:
+		# Running "svn info" creates a ~/.subversion directory, which is
+		# undesired on automated build machines and pkgsrc complains about it.
+		return None
 	if not isdir('derived'):
 		makedirs('derived')
 	log = open('derived/version.log', 'w')
