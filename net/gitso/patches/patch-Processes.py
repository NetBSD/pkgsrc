$NetBSD: patch-Processes.py,v 1.1 2012/04/11 19:32:17 darcy Exp $

Test for BSD systems

--- share/gitso/Processes.py.orig	2010-02-22 02:48:04.000000000 +0000
+++ share/gitso/Processes.py
@@ -35,7 +35,7 @@ class Processes:
 	def getSupport(self, host):
 		if sys.platform == 'darwin':
 			self.returnPID = os.spawnl(os.P_NOWAIT, '%sOSXvnc/OSXvnc-server' % self.paths['resources'], '%sOSXvnc/OSXvnc-server' % self.paths['resources'], '-connectHost', '%s' % host)
-		elif sys.platform.find('linux') != -1:
+		elif sys.platform.find('linux') != -1 or sys.platform.find('bsd'):
 			# We should include future versions with options for speed.
 			#self.returnPID = os.spawnlp(os.P_NOWAIT, 'x11vnc', 'x11vnc','-nopw','-ncache','20','-solid','black','-connect','%s' % host)
 			
@@ -59,7 +59,7 @@ class Processes:
 		if sys.platform == 'darwin':
 			vncviewer = '%scotvnc.app/Contents/MacOS/cotvnc' % self.paths['resources']
 			self.returnPID = os.spawnlp(os.P_NOWAIT, vncviewer, vncviewer, '--listen')
-		elif sys.platform.find('linux') != -1:
+		elif sys.platform.find('linux') != -1 or sys.platform.find('bsd'):
 			self.returnPID = os.spawnlp(os.P_NOWAIT, 'vncviewer', 'vncviewer', '-listen')
 			
 			# These are the options for low-res connections.
