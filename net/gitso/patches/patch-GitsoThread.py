$NetBSD: patch-GitsoThread.py,v 1.1 2012/04/11 19:32:17 darcy Exp $

Test for BSD systems

--- share/gitso/GitsoThread.py.orig	2010-02-22 02:48:04.000000000 +0000
+++ share/gitso/GitsoThread.py
@@ -122,7 +122,7 @@ class GitsoThread(threading.Thread):
 		
 		connection = []
 		listen = []
-		if sys.platform == 'darwin' or sys.platform.find('linux') != -1:
+		if sys.platform == 'darwin' or sys.platform.find('linux') != -1 or sys.platform.find('bsd'):
 			if self.host <> "":
 				connection = os.popen('LANG=C netstat -an | grep 5500 | grep ESTABLISHED').readlines()
 			else:
