$NetBSD: patch-setup.py,v 1.3 2015/11/18 17:12:44 nros Exp $

* in config.py: adjust license filename and add doc_path
  to point at the local docs
* nautilus-python is not available in pkgsrc so don't install
  the nautilus extension.
* Install html documention, desktop file and license file.

--- setup.py.orig	2015-11-09 16:49:02.000000000 +0000
+++ setup.py
@@ -11,6 +11,7 @@ import sys
 import os
 import shutil
 import cgi
+import string
 import tempfile
 import re
 import tarfile
@@ -205,10 +206,11 @@ class build_config(Command):
         data = {
             'bin_path': installcmd.install_scripts[rootlen:],
             'license_path': os.path.join(sharedir, 'doc', 'tortoisehg',
-                                         'Copying.txt.gz'),
+                                         'COPYING.txt'),
             'locale_path': os.path.join(sharedir, 'locale'),
             'icon_path': os.path.join(sharedir, 'pixmaps', 'tortoisehg',
                                       'icons'),
+            'doc_path' : os.path.join(sharedir, 'doc', 'tortoisehg'),
             'nofork': True,
             }
         # Distributions will need to supply their own
@@ -569,8 +571,14 @@ def setup_posix():
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
 
