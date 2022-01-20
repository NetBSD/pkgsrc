$NetBSD: patch-setup_build.py,v 1.5 2022/01/20 19:03:07 rhialto Exp $

- Fix linking against native X.
- Include netbsd in various conditional building criteria.
- Patch in the directory /usr/pkg/share/sip3.9/PyQt5 for
  QtWidgets/QtWidgetsmod.sip etc.
- Define the %Platform value WS_X11, so that Q_PID gets defined in
  PyQt5/QtCore/qprocess.sip.
- Autodetection of the sip API version of PyQt5.so fails because sip 4
  does not write the QtCore.toml file with that information.

--- setup/build.py.orig	2021-12-17 00:40:19.000000000 +0000
+++ setup/build.py
@@ -8,7 +8,7 @@ __docformat__ = 'restructuredtext en'
 import textwrap, os, shlex, subprocess, glob, shutil, sys, json, errno, sysconfig
 from collections import namedtuple
 
-from setup import Command, islinux, isbsd, isfreebsd, ismacos, ishaiku, SRC, iswindows
+from setup import Command, islinux, isbsd, isfreebsd, ismacos, ishaiku, SRC, iswindows, isnetbsd
 isunix = islinux or ismacos or isbsd or ishaiku
 
 py_lib = os.path.join(sys.prefix, 'libs', 'python%d%d.lib' % sys.version_info[:2])
@@ -116,7 +116,7 @@ def is_ext_allowed(ext):
     only = ext.get('only', '')
     if only:
         only = set(only.split())
-        q = set(filter(lambda x: globals()["is" + x], ["bsd", "freebsd", "haiku", "linux", "macos", "windows"]))
+        q = set(filter(lambda x: globals()["is" + x], ["bsd", "freebsd", "haiku", "linux", "macos", "windows", "netbsd"]))
         return len(q.intersection(only)) > 0
     return True
 
@@ -137,6 +137,8 @@ def parse_extension(ext):
             ans = ext.pop('bsd_' + k, ans)
         elif isfreebsd:
             ans = ext.pop('freebsd_' + k, ans)
+        elif isnetbsd:
+            ans = ext.pop('netbsd_' + k, ans)
         elif ishaiku:
             ans = ext.pop('haiku_' + k, ans)
         else:
@@ -496,6 +498,7 @@ class Build(Command):
             INCLUDEPATH += {freetype}
             DESTDIR = {destdir}
             CONFIG -= create_cmake  # Prevent qmake from generating a cmake build file which it puts in the calibre src directory
+            QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
             ''').format(
                 headers=' '.join(headers), sources=' '.join(sources), others=' '.join(others), destdir=self.d(
                     target), freetype=' '.join(ft_inc_dirs))
@@ -521,8 +524,11 @@ class Build(Command):
         abi_version = ''
         if pyqt_sip_abi_version():
             abi_version = f'abi-version = "{pyqt_sip_abi_version()}"'
+        else:
+            abi_version = f'abi-version = "12.7"'   # 12.7 sip-4.19.25
         sipf = ext.sip_files[0]
         needs_exceptions = 'true' if ext.needs_exceptions else 'false'
+        sip_include_dirs = [os.getenv('SIP_DIR')]
         with open(os.path.join(src_dir, 'pyproject.toml'), 'w') as f:
             f.write(f'''
 [build-system]
@@ -538,6 +544,7 @@ project-factory = "pyqtbuild:PyQtProject
 
 [tool.sip.project]
 sip-files-dir = "."
+sip-include-dirs = {sip_include_dirs}
 {abi_version}
 
 [tool.sip.bindings.pictureflow]
@@ -547,6 +554,7 @@ exceptions = {needs_exceptions}
 include-dirs = {ext.inc_dirs}
 qmake-QT = ["widgets"]
 sip-file = "{os.path.basename(sipf)}"
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
