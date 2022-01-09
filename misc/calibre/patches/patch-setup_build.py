$NetBSD: patch-setup_build.py,v 1.4 2022/01/09 15:43:51 rhialto Exp $

- Fix linking against native X.
- Include netbsd in various conditional building criteria.

--- setup/build.py.orig	2020-02-21 03:27:12.000000000 +0000
+++ setup/build.py
@@ -10,7 +10,7 @@ __docformat__ = 'restructuredtext en'
 import textwrap, os, shlex, subprocess, glob, shutil, re, sys, json
 from collections import namedtuple
 
-from setup import Command, islinux, isbsd, isfreebsd, isosx, ishaiku, SRC, iswindows, __version__, ispy3
+from setup import Command, islinux, isbsd, isfreebsd, isnetbsd, isosx, ishaiku, SRC, iswindows, __version__, ispy3
 isunix = islinux or isosx or isbsd or ishaiku
 
 py_lib = os.path.join(sys.prefix, 'libs', 'python%d%d.lib' % sys.version_info[:2])
@@ -103,7 +103,7 @@ def is_ext_allowed(ext):
     only = ext.get('only', '')
     if only:
         only = set(only.split())
-        q = set(filter(lambda x: globals()["is" + x], ["bsd", "freebsd", "haiku", "linux", "osx", "windows"]))
+        q = set(filter(lambda x: globals()["is" + x], ["bsd", "freebsd", "haiku", "linux", "osx", "windows", "netbsd"]))
         return len(q.intersection(only)) > 0
     return True
 
@@ -124,6 +124,8 @@ def parse_extension(ext):
             ans = ext.pop('bsd_' + k, ans)
         elif isfreebsd:
             ans = ext.pop('freebsd_' + k, ans)
+        elif isnetbsd:
+            ans = ext.pop('netbsd_' + k, ans)
         elif ishaiku:
             ans = ext.pop('haiku_' + k, ans)
         else:
@@ -412,6 +414,7 @@ class Build(Command):
             INCLUDEPATH += {freetype}
             DESTDIR = {destdir}
             CONFIG -= create_cmake  # Prevent qmake from generating a cmake build file which it puts in the calibre src directory
+            QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
             ''').format(
                 headers=' '.join(headers), sources=' '.join(sources), others=' '.join(others), destdir=self.d(
                     target), freetype=' '.join(ft_inc_dirs))
@@ -472,6 +475,7 @@ class Build(Command):
         SOURCES = {sources}
         INCLUDEPATH += {sipinc} {pyinc}
         VERSION = {ver}
+        QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
         win32 {{
             LIBS += {py_lib}
             TARGET_EXT = .dll
