$NetBSD: patch-setup_build.py,v 1.2 2016/09/29 12:13:43 joerg Exp $

Find libtool output correctly.
Fix linking against native X.

--- setup/build.py.orig	2016-09-29 10:28:31.000000000 +0000
+++ setup/build.py
@@ -368,6 +368,7 @@ class Build(Command):
             INCLUDEPATH += {freetype}
             DESTDIR = {destdir}
             CONFIG -= create_cmake  # Prevent qmake from generating a cmake build file which it puts in the calibre src directory
+            QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
             QMAKE_LIBS_PRIVATE += {glib} {fontconfig}
             ''').format(
                 headers=' '.join(headers), sources=' '.join(sources), others=' '.join(others), destdir=self.d(
@@ -426,6 +427,7 @@ class Build(Command):
         SOURCES = {sources}
         INCLUDEPATH += {sipinc} {pyinc}
         VERSION = {ver}
+        QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
         win32 {{
             LIBS += {py_lib}
             TARGET_EXT = .dll
@@ -456,7 +458,7 @@ class Build(Command):
         if iswindows:
             qmc += ['-spec', qmakespec]
         fext = 'dll' if iswindows else 'dylib' if isosx else 'so'
-        name = '%s%s.%s' % ('release/' if iswindows else 'lib', sip['target'], fext)
+        name = '%s%s.%s' % ('release/' if iswindows else '.libs/lib', sip['target'], fext)
         try:
             os.chdir(src_dir)
             if self.newer(dest, sip['headers'] + sip['sources'] + ext.sources + ext.headers):
