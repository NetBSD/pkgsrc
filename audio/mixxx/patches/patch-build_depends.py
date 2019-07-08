$NetBSD: patch-build_depends.py,v 1.1 2019/07/08 16:46:32 nia Exp $

- Search in LOCALBASE.
- Use pkg-config on BSD where possible.
- Disable PortMIDI dependency.

--- build/depends.py.orig	2019-04-22 07:50:04.000000000 +0000
+++ build/depends.py
@@ -12,7 +12,7 @@ class PortAudio(Dependence):
         if not conf.CheckLib('portaudio'):
             raise Exception(
                 'Did not find libportaudio.a, portaudio.lib, or the PortAudio-v19 development header files.')
-        elif build.platform_is_linux:
+        elif build.platform_is_linux or build.platform_is_bsd:
             build.env.ParseConfig('pkg-config portaudio-2.0 --silence-errors --cflags --libs')
 
         # Turn on PortAudio support in Mixxx
@@ -123,7 +123,7 @@ class IOKit(Dependence):
 class UPower(Dependence):
     """UPower is used to get battery measurements on Linux."""
     def configure(self, build, conf):
-        if not build.platform_is_linux:
+        if not build.platform_is_linux and not build.platform_is_bsd:
             return
         build.env.ParseConfig(
                 'pkg-config upower-glib --silence-errors --cflags --libs')
@@ -206,12 +206,14 @@ class Qt(Dependence):
                        'osx': '/Library/Frameworks',
                        'windows': 'C:\\qt\\4.6.0'}
 
-    DEFAULT_QT5DIRS64 = {'linux': '/usr/lib/x86_64-linux-gnu/qt5',
-                         'osx': '/Library/Frameworks',
+    DEFAULT_QT5DIRS64 = {'linux': '@LOCALBASE@/qt5/lib',
+                         'bsd': '@LOCALBASE@/qt5/lib',
+                         'osx': '@LOCALBASE@/qt5/lib',
                          'windows': 'C:\\qt\\5.11.1'}
 
-    DEFAULT_QT5DIRS32 = {'linux': '/usr/lib/i386-linux-gnu/qt5',
-                         'osx': '/Library/Frameworks',
+    DEFAULT_QT5DIRS32 = {'linux': '@LOCALBASE@/qt5/lib',
+                         'bsd': '@LOCALBASE@/qt5/lib',
+                         'osx': '@LOCALBASE@/qt5/lib',
                          'windows': 'C:\\qt\\5.11.1'}
 
     @staticmethod
@@ -227,7 +229,7 @@ class Qt(Dependence):
     def find_framework_libdir(qtdir, qt5):
         # Try pkg-config on Linux
         import sys
-        if sys.platform.startswith('linux'):
+	if sys.platform.startswith('linux') or sys.platform.find('bsd') >= 0:
             if any(os.access(os.path.join(path, 'pkg-config'), os.X_OK) for path in os.environ["PATH"].split(os.pathsep)):
                 import subprocess
                 try:
@@ -319,16 +321,19 @@ class Qt(Dependence):
             conf.CheckLib('sqlite3');
 
         # Enable Qt include paths
-        if build.platform_is_linux:
+        if build.platform_is_linux or build.platform_is_bsd:
             if qt5 and not conf.CheckForPKG('Qt5Core', '5.0'):
                 raise Exception('Qt >= 5.0 not found')
             elif not qt5 and not conf.CheckForPKG('QtCore', '4.6'):
                 raise Exception('QT >= 4.6 not found')
 
-            if not conf.CheckLib('Qt5X11Extras'):
-                raise Exception('Could not find Qt5X11Extras or its development headers')
-
             qt_modules.extend(['QtDBus'])
+
+            for module in qt_modules:
+                module = 'Qt5' + module[2:]
+                if not conf.CheckLib(module):
+                    raise Exception('Could not find %s or its development headers' % module)
+
             # This automatically converts QtXXX to Qt5XXX where appropriate.
             if qt5:
                 build.env.EnableQt5Modules(qt_modules, debug=False)
@@ -339,12 +344,6 @@ class Qt(Dependence):
                 # Note that -reduce-relocations is enabled by default in Qt5.
                 # So we must build the code with position independent code
                 build.env.Append(CCFLAGS='-fPIC')
-
-        elif build.platform_is_bsd:
-            build.env.Append(LIBS=qt_modules)
-            include_paths = ['$QTDIR/include/%s' % module
-                             for module in qt_modules]
-            build.env.Append(CPPPATH=include_paths)
         elif build.platform_is_osx:
             qtdir = build.env['QTDIR']
             build.env.Append(
@@ -603,7 +602,7 @@ class SoundTouch(Dependence):
         if env is None:
             env = build.env
 
-        if build.platform_is_linux:
+        if build.platform_is_linux or build.platform_is_bsd:
             # Try using system lib
             if conf.CheckForPKG('soundtouch', '2.0.0'):
                 # System Lib found
@@ -647,7 +646,7 @@ class TagLib(Dependence):
         # the files correctly. Adding this folder to the include path should fix
         # it, though might cause issues. This is safe to remove once we
         # deprecate Karmic support. rryan 2/2011
-        build.env.Append(CPPPATH='/usr/include/taglib/')
+        build.env.Append(CPPPATH='@LOCALBASE@/include/taglib/')
 
         if build.platform_is_windows and build.static_dependencies:
             build.env.Append(CPPDEFINES='TAGLIB_STATIC')
@@ -1471,12 +1470,12 @@ class MixxxCore(Feature):
 
         elif build.platform_is_osx:
             # Stuff you may have compiled by hand
-            if os.path.isdir('/usr/local/include'):
-                build.env.Append(LIBPATH=['/usr/local/lib'])
+            if os.path.isdir('@LOCALBASE@/include'):
+                build.env.Append(LIBPATH=['@LOCALBASE@/lib'])
                 # Use -isystem instead of -I to avoid compiler warnings from
                 # system libraries. This cuts down on Mixxx's compilation output
                 # significantly when using Homebrew installed to /usr/local.
-                build.env.Append(CCFLAGS=['-isystem', '/usr/local/include'])
+                build.env.Append(CCFLAGS=['-isystem', '@LOCALBASE@/include'])
 
             # Non-standard libpaths for fink and certain (most?) darwin ports
             if os.path.isdir('/sw/include'):
@@ -1492,10 +1491,12 @@ class MixxxCore(Feature):
             build.env.Append(CPPDEFINES='__BSD__')
             build.env.Append(CPPPATH=['/usr/include',
                                       '/usr/local/include',
-                                      '/usr/X11R6/include/'])
+                                      '/usr/X11R6/include',
+                                      '@LOCALBASE@/include'])
             build.env.Append(LIBPATH=['/usr/lib/',
                                       '/usr/local/lib',
-                                      '/usr/X11R6/lib'])
+                                      '/usr/X11R6/lib',
+                                      '@LOCALBASE@/lib'])
             build.env.Append(LIBS='pthread')
             # why do we need to do this on OpenBSD and not on Linux?  if we
             # don't then CheckLib("vorbisfile") fails
@@ -1532,7 +1533,7 @@ class MixxxCore(Feature):
         # Say where to find resources on Unix. TODO(XXX) replace this with a
         # RESOURCE_PATH that covers Win and OSX too:
         if build.platform_is_linux or build.platform_is_bsd:
-            prefix = SCons.ARGUMENTS.get('prefix', '/usr/local')
+            prefix = SCons.ARGUMENTS.get('prefix', '@LOCALBASE@')
             share_path = os.path.join (prefix, build.env.get(
                 'SHAREDIR', default='share'), 'mixxx')
             build.env.Append(
@@ -1543,7 +1544,7 @@ class MixxxCore(Feature):
                 CPPDEFINES=('UNIX_LIB_PATH', r'\"%s\"' % lib_path))
 
     def depends(self, build):
-        return [SoundTouch, ReplayGain, Ebur128Mit, PortAudio, PortMIDI, Qt, TestHeaders,
+        return [SoundTouch, ReplayGain, Ebur128Mit, PortAudio, Qt, TestHeaders,
                 FidLib, SndFile, FLAC, OggVorbis, OpenGL, TagLib, ProtoBuf,
                 Chromaprint, RubberBand, SecurityFramework, CoreServices, Foundation, IOKit,
                 QtScriptByteArray, Reverb, FpClassify, PortAudioRingBuffer, OSXFilePathUrlBackport]
