$NetBSD: patch-src_coccigrep.py,v 1.1 2024/10/13 16:38:37 wiz Exp $

Fix Python 3.12 support.
https://github.com/regit/coccigrep/commit/98a57cb9707b157d5f27d6f65c944437e7fcdee6

--- src/coccigrep.py.orig	2020-05-05 07:56:05.000000000 +0000
+++ src/coccigrep.py
@@ -15,9 +15,9 @@
 # 02110-1301, USA.
 
 try:
-    from configparser import SafeConfigParser
+    from configparser import ConfigParser as PyConfigParser
 except Exception:
-    from ConfigParser import SafeConfigParser
+    from ConfigParser import SafeConfigParser as PyConfigParser
 from os import unlink, path, listdir, getcwd
 from string import Template
 from subprocess import Popen, PIPE, STDOUT
@@ -88,16 +88,16 @@ _CONF_FILES = tuple((path.join(dirname, 
     (getcwd(), '.%s'))))
 
 
-class CocciGrepConfig(SafeConfigParser):
+class CocciGrepConfig(PyConfigParser):
     """
     Configuration handling class
 
     This class parses configuration and can be used to access to
     configuration item via get operations. CocciGrepConfig is derived
-    from SafeConfigParser
+    from ConfigParser
     """
     def __init__(self):
-        SafeConfigParser.__init__(self)
+        PyConfigParser.__init__(self)
         self._load_config()
 
     def _load_config(self):
