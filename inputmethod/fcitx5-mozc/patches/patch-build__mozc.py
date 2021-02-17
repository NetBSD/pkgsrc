$NetBSD: patch-build__mozc.py,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- build_mozc.py.orig	2021-02-15 03:48:53.000000000 +0000
+++ build_mozc.py
@@ -55,6 +55,7 @@ from build_tools.util import CopyFile
 from build_tools.util import GetNumberOfProcessors
 from build_tools.util import IsLinux
 from build_tools.util import IsMac
+from build_tools.util import IsNetBSD
 from build_tools.util import IsWindows
 from build_tools.util import PrintErrorAndExit
 from build_tools.util import RemoveDirectoryRecursively
@@ -96,6 +97,7 @@ def GetBuildShortBaseName(target_platfor
       'Windows': 'out_win',
       'Mac': 'out_mac',
       'Linux': 'out_linux',
+      'NetBSD': 'out_bsd',
       'iOS': 'out_ios',
   }
 
@@ -155,7 +157,7 @@ def GetGypFileNames(options):
   # Include subdirectory of win32 and breakpad for Windows
   if options.target_platform == 'Windows':
     gyp_file_names.extend(glob.glob('%s/win32/*/*.gyp' % SRC_DIR))
-  elif options.target_platform == 'Linux':
+  elif options.target_platform == 'Linux' or options.target_platform == 'NetBSD':
     gyp_file_names.extend(glob.glob('%s/unix/*/*.gyp' % SRC_DIR))
     # Add ibus.gyp if ibus version is >=1.4.1.
     if not PkgExists('ibus-1.0 >= 1.4.1'):
@@ -182,6 +184,8 @@ def ParseVerbose(unused_option, unused_o
 def AddTargetPlatformOption(parser):
   if IsLinux():
     default_target = 'Linux'
+  if IsNetBSD():
+    default_target = 'NetBSD'
   elif IsWindows():
     default_target = 'Windows'
   elif IsMac():
@@ -269,6 +273,12 @@ def ExpandMetaTarget(options, meta_targe
                SRC_DIR + '/gui/gui.gyp:mozc_tool']
     if PkgExists('ibus-1.0 >= 1.4.1'):
       targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
+  elif target_platform == 'NetBSD':
+    targets = [SRC_DIR + '/server/server.gyp:mozc_server',
+               SRC_DIR + '/renderer/renderer.gyp:mozc_renderer',
+               SRC_DIR + '/gui/gui.gyp:mozc_tool']
+    if PkgExists('ibus-1.0 >= 1.4.1'):
+      targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
   elif target_platform == 'Mac':
     targets = [SRC_DIR + '/mac/mac.gyp:codesign_DiskImage']
   elif target_platform == 'Windows':
@@ -441,7 +451,8 @@ def GypMain(options, unused_args):
   if options.noqt:
     gyp_options.extend(['-D', 'use_qt=NO'])
     gyp_options.extend(['-D', 'qt_dir='])
-  elif target_platform == 'Linux':
+  elif (target_platform == 'Linux' or
+       target_platform == 'NetBSD'):
     gyp_options.extend(['-D', 'use_qt=YES'])
     gyp_options.extend(['-D', 'qt_dir='])
 
@@ -482,7 +493,8 @@ def GypMain(options, unused_args):
   if IsWindows():
     gyp_options.extend(['-G', 'msvs_version=2017'])
 
-  if (target_platform == 'Linux' and
+  if ((target_platform == 'Linux' or
+       target_platform == 'NetBSD') and
       '%s/unix/ibus/ibus.gyp' % SRC_DIR in gyp_file_names):
     gyp_options.extend(['-D', 'use_libibus=1'])
 
