$NetBSD: patch-setup.py,v 1.1 2014/07/05 15:33:03 wiz Exp $

* nautilus-python is not available in pkgsrc so don't install
  the nautilus extension.
* Install html documention, desktop file and license file.

--- setup.py.orig	2013-11-16 07:12:03.000000000 +0000
+++ setup.py
@@ -11,6 +11,7 @@ import time
 import sys
 import os
 import shutil
+import string
 import subprocess
 import cgi
 import tempfile
@@ -504,8 +505,13 @@ def setup_posix():
     _data_files += [(os.path.join('share', root),
         [os.path.join(root, file_) for file_ in files])
         for root, dirs, files in os.walk('locale')]
-    _data_files += [('/usr/share/nautilus-python/extensions/',
-                     ['contrib/nautilus-thg.py'])]
+    _data_files += [(os.path.join('share/doc/tortoisehg', 
+                                  string.replace(root,'doc/build/html','html',1)),
+        [os.path.join(root, file_) for file_ in files])
+        for root, dirs, files in os.walk('doc/build/html')]
+    _data_files += [('share/doc/tortoisehg/',['COPYING.txt'])]
+    _data_files += [('share/applications', ['contrib/thg.desktop'])]
+    _data_files += [('share/tortoisehg', ['contrib/mergetools.rc'])]
 
     # Create a config.py.  Distributions will need to supply their own
     cfgfile = os.path.join('tortoisehg', 'util', 'config.py')
