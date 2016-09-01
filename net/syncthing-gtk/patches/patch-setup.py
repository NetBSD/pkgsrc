$NetBSD: patch-setup.py,v 1.2 2016/09/01 17:30:21 wiz Exp $

Avoid calling git.
Install man page in proper directory for pkgsrc.

--- setup.py.orig	2016-08-29 04:05:55.000000000 +0000
+++ setup.py
@@ -12,13 +12,6 @@ def get_version():
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
@@ -82,7 +75,7 @@ if __name__ == "__main__" : 
 				"icons/%s.png" % x for x in (
 					'restart', 'settings', 'shutdown', "st-gtk-logo"
 			)]),
-		('share/man/man1', glob.glob("doc/*") ),
+		(os.environ['PKGMANDIR'] + '/man1', glob.glob("doc/*") ),
 		('share/icons/hicolor/64x64/emblems', glob.glob("icons/emblem-*.png") ),
 		('share/pixmaps', ["icons/syncthing-gtk.png"]),
 		('share/applications', ['syncthing-gtk.desktop'] ),
