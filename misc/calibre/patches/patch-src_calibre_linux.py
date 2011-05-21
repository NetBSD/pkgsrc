$NetBSD: patch-src_calibre_linux.py,v 1.1 2011/05/21 15:07:48 wiz Exp $

--- src/calibre/linux.py.orig	2011-05-13 17:49:55.000000000 +0000
+++ src/calibre/linux.py
@@ -7,7 +7,7 @@ import sys, os, cPickle, textwrap, stat,
 from subprocess import check_call
 
 from calibre import  __appname__, prints, guess_type
-from calibre.constants import islinux, isfreebsd
+from calibre.constants import islinux, isfreebsd, isnetbsd, isbsd
 from calibre.customize.ui import all_input_formats
 from calibre.ptempfile import TemporaryDirectory
 from calibre import CurrentDir
@@ -136,17 +136,17 @@ class PostInstall:
         self.icon_resources = []
         self.menu_resources = []
         self.mime_resources = []
-        if islinux or isfreebsd:
+        if islinux or isbsd:
             self.setup_completion()
         self.install_man_pages()
-        if islinux or isfreebsd:
+        if islinux or isbsd:
             self.setup_desktop_integration()
         self.create_uninstaller()
 
         from calibre.utils.config import config_dir
         if os.path.exists(config_dir):
             os.chdir(config_dir)
-            if islinux or isfreebsd:
+            if islinux or isbsd:
                 for f in os.listdir('.'):
                     if os.stat(f).st_uid == 0:
                         import shutil
@@ -196,7 +196,10 @@ class PostInstall:
             if os.path.exists(bc):
                 f = os.path.join(bc, 'calibre')
             else:
-                f = os.path.join(self.opts.staging_etc, 'bash_completion.d/calibre')
+		if isnetbsd:
+		    f = os.path.join(self.opts.staging_root, 'share/bash_completion.d/calibre')
+		else:
+		    f = os.path.join(self.opts.staging_etc, 'bash_completion.d/calibre')
             if not os.path.exists(os.path.dirname(f)):
                 os.makedirs(os.path.dirname(f))
             self.manifest.append(f)
@@ -300,7 +303,7 @@ class PostInstall:
     def install_man_pages(self): # {{{
         try:
             from calibre.utils.help2man import create_man_page
-            if isfreebsd:
+            if isbsd:
                 manpath = os.path.join(self.opts.staging_root, 'man/man1')
             else:
                 manpath = os.path.join(self.opts.staging_sharedir, 'man/man1')
@@ -316,7 +319,7 @@ class PostInstall:
                     continue
                 parser = parser()
                 raw = create_man_page(prog, parser)
-                if isfreebsd:
+                if isbsd:
                     manfile = os.path.join(manpath, prog+'.1')
                 else:
                     manfile = os.path.join(manpath, prog+'.1'+__appname__+'.bz2')
