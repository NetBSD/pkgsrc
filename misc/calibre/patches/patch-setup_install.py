$NetBSD: patch-setup_install.py,v 1.1 2011/05/21 15:07:48 wiz Exp $

--- setup/install.py.orig	2011-05-20 13:49:07.000000000 +0000
+++ setup/install.py
@@ -8,7 +8,7 @@ __docformat__ = 'restructuredtext en'
 
 import sys, os, textwrap, subprocess, shutil, tempfile, atexit, stat, shlex
 
-from setup import Command, islinux, isfreebsd, basenames, modules, functions, \
+from setup import Command, islinux, isfreebsd, isbsd, basenames, modules, functions, \
         __appname__, __version__
 
 HEADER = '''\
@@ -116,7 +116,7 @@ class Develop(Command):
 
 
     def pre_sub_commands(self, opts):
-        if not (islinux or isfreebsd):
+        if not (islinux or isbsd):
             self.info('\nSetting up a source based development environment is only '
                     'supported on linux. On other platforms, see the User Manual'
                     ' for help with setting up a development environment.')
@@ -156,7 +156,7 @@ class Develop(Command):
             self.warn('Failed to compile mount helper. Auto mounting of',
                 ' devices will not work')
 
-        if not isfreebsd and os.geteuid() != 0:
+        if not isbsd and os.geteuid() != 0:
             return self.warn('Must be run as root to compile mount helper. Auto '
                     'mounting of devices will not work.')
         src = os.path.join(self.SRC, 'calibre', 'devices', 'linux_mount_helper.c')
@@ -168,7 +168,7 @@ class Develop(Command):
         ret = p.wait()
         if ret != 0:
             return warn()
-        if not isfreebsd:
+        if not isbsd:
             os.chown(dest, 0, 0)
             os.chmod(dest, stat.S_ISUID|stat.S_ISGID|stat.S_IRUSR|stat.S_IWUSR|\
                     stat.S_IXUSR|stat.S_IXGRP|stat.S_IXOTH)
