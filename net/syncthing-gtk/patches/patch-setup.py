$NetBSD: patch-setup.py,v 1.1 2015/10/03 16:28:56 tnn Exp $

Avoid calling git.

--- setup.py.orig	2015-02-12 13:40:21.000000000 +0000
+++ setup.py
@@ -9,13 +9,6 @@ def get_version():
 	Returns current package version using git-describe or examining
 	path. If both methods fails, returns 'unknown'.
 	"""
-	try:
-		p = Popen(['git', 'describe', '--tags', '--match', 'v*'], stdout=PIPE)
-		version = p.communicate()[0].strip("\n\r \t")
-		if p.returncode != 0:
-			raise Exception("git-describe failed")
-		return version
-	except: pass
 	# Git-describe method failed, try to guess from working directory name
 	path = os.getcwd().split(os.path.sep)
 	version = 'unknown'
