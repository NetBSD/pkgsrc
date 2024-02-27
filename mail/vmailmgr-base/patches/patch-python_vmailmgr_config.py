$NetBSD: patch-python_vmailmgr_config.py,v 1.1 2024/02/27 19:13:44 schmonz Exp $

Port to Python 3, maintaining 2.7 compatibility.

--- python/vmailmgr/config.py.orig	2015-09-01 16:03:21.000000000 +0000
+++ python/vmailmgr/config.py
@@ -15,13 +15,12 @@
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
 import os
-import string
-import local
+import vmailmgr.local
 
 def read(name, default):
     try:
-        file = open(os.path.join(vmailmgr_local.sysconfdir, name))
-        result = string.strip(file.readline())
+        file = open(os.path.join(vmailmgr.local.sysconfdir, name))
+        result = file.readline().strip()
         file.close()
     except:
         result = default
