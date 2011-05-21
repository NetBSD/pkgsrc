$NetBSD: patch-setup_extensions.py,v 1.1 2011/05/21 15:07:48 wiz Exp $

--- setup/extensions.py.orig	2011-05-20 14:36:29.000000000 +0000
+++ setup/extensions.py
@@ -11,7 +11,7 @@ from distutils import sysconfig
 
 from PyQt4.pyqtconfig import QtGuiModuleMakefile
 
-from setup import Command, islinux, isfreebsd, isosx, SRC, iswindows
+from setup import Command, islinux, isfreebsd, isbsd, isosx, SRC, iswindows
 from setup.build_environment import fc_inc, fc_lib, chmlib_inc_dirs, \
         fc_error, poppler_libs, poppler_lib_dirs, poppler_inc_dirs, podofo_inc, \
         podofo_lib, podofo_error, poppler_error, pyqt, OSX_SDK, NMAKE, \
@@ -21,7 +21,7 @@ from setup.build_environment import fc_i
         jpg_lib_dirs, chmlib_lib_dirs, sqlite_inc_dirs, icu_inc_dirs, \
         icu_lib_dirs
 MT
-isunix = islinux or isosx or isfreebsd
+isunix = islinux or isosx or isbsd
 
 make = 'make' if isunix else NMAKE
 
@@ -205,7 +205,7 @@ if islinux:
     ldflags.append('-lpython'+sysconfig.get_python_version())
 
 
-if isfreebsd:
+if isbsd:
     cflags.append('-pthread')
     ldflags.append('-shared')
     cflags.append('-I'+sysconfig.get_python_inc())
