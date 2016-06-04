$NetBSD: patch-setup_extensions.py,v 1.7 2016/06/04 12:06:07 joerg Exp $

Fix build for pictureflow.

--- setup/extensions.py.orig	2016-02-26 03:04:36.000000000 +0000
+++ setup/extensions.py
@@ -549,6 +549,7 @@ class Build(Command):
             INCLUDEPATH += {freetype}
             DESTDIR = {destdir}
             CONFIG -= create_cmake  # Prevent qmake from generating a cmake build file which it puts in the calibre src directory
+            QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
             QMAKE_LIBS_PRIVATE += {glib} {fontconfig}
             ''').format(
                 headers=' '.join(headers), sources=' '.join(sources), others=' '.join(others), destdir=self.d(
@@ -603,6 +604,8 @@ class Build(Command):
         SOURCES = {sources}
         INCLUDEPATH += {sipinc} {pyinc}
         VERSION = {ver}
+        QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
+
         win32 {{
             LIBS += {py_lib}
             TARGET_EXT = .dll
@@ -633,7 +636,7 @@ class Build(Command):
         if iswindows:
             qmc += ['-spec', qmakespec]
         fext = 'dll' if iswindows else 'dylib' if isosx else 'so'
-        name = '%s%s.%s' % ('release/' if iswindows else 'lib', sip['target'], fext)
+        name = '%s%s.%s' % ('release/' if iswindows else '.libs/lib', sip['target'], fext)
         try:
             os.chdir(src_dir)
             if self.newer(dest, sip['headers'] + sip['sources'] + ext.sources + ext.headers):
