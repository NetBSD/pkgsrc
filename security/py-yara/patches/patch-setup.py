$NetBSD: patch-setup.py,v 1.1 2024/06/11 10:29:52 adam Exp $

Enable dynamic linking.

--- setup.py.orig	2024-06-11 10:22:41.052942022 +0000
+++ setup.py
@@ -31,7 +31,7 @@ import shutil
 import subprocess
 
 OPTIONS = [
-   ('dynamic-linking', None, 'link dynamically against libyara'),
+   ('dynamic-linking', True, 'link dynamically against libyara'),
    ('enable-cuckoo', None, 'enable "cuckoo" module'),
    ('enable-magic', None, 'enable "magic" module'),
    ('enable-dex', None, 'enable "dex" module'),
@@ -118,7 +118,7 @@ class BuildCommand(build):
   def initialize_options(self):
 
     build.initialize_options(self)
-    self.dynamic_linking = None
+    self.dynamic_linking = True
     self.enable_magic = None
     self.enable_cuckoo = None
     self.enable_dex = None
@@ -140,7 +140,7 @@ class BuildExtCommand(build_ext):
   def initialize_options(self):
 
     build_ext.initialize_options(self)
-    self.dynamic_linking = None
+    self.dynamic_linking = True
     self.enable_magic = None
     self.enable_cuckoo = None
     self.enable_dex = None
