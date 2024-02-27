$NetBSD: patch-python_vmailmgr_daemon.py,v 1.1 2024/02/27 19:13:44 schmonz Exp $

Port to Python 3, maintaining 2.7 compatibility.

--- python/vmailmgr/daemon.py.orig	2015-09-01 16:03:21.000000000 +0000
+++ python/vmailmgr/daemon.py
@@ -14,7 +14,7 @@
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
-import config
+import vmailmgr.config
 
 ok = 0
 bad = 1
@@ -47,7 +47,7 @@ class Command:
 
 class Daemon:
     def __init__(self):
-        self.socket_file = config.read('socket-file', '/tmp/.vmailmgrd')
+        self.socket_file = vmailmgr.config.read('socket-file', '/tmp/.vmailmgrd')
         self.socket = None
 
     def connect(self):
