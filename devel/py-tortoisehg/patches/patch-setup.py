$NetBSD: patch-setup.py,v 1.2 2015/08/14 18:00:56 wiz Exp $

* nautilus-python is not available in pkgsrc so don't install
  the nautilus extension.
* Install html documention, desktop file and license file.

--- setup.py.orig	2015-08-06 01:30:23.000000000 +0000
+++ setup.py
@@ -11,6 +11,7 @@ import sys
 import os
 import shutil
 import cgi
+import string
 import tempfile
 import re
 import tarfile
@@ -569,8 +570,14 @@ def setup_posix():
                             [os.path.join(root, f) for f in files]))
     _data_files.extend((os.path.join('share', modir), [mofile])
                        for pofile, modir, mofile in _walklocales())
-    _data_files += [('share/nautilus-python/extensions',
-                     ['contrib/nautilus-thg.py'])]
+
+    _data_files += [(os.path.join('share/doc/tortoisehg',
+                                  string.replace(root,'doc/build/html','html',1)),
+        [os.path.join(root, file_) for file_ in files])
+        for root, dirs, files in os.walk('doc/build/html')]
+    _data_files += [('share/doc/tortoisehg/',['COPYING.txt'])]
+    _data_files += [('share/applications', ['contrib/thg.desktop'])]
+    _data_files += [('share/tortoisehg', ['contrib/mergetools.rc'])]
 
     return _scripts, _packages, _data_files, _extra
 
