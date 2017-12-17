$NetBSD: patch-build__mozc.py,v 1.9 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- build_mozc.py.orig	2017-11-02 13:32:45.000000000 +0000
+++ build_mozc.py
@@ -58,6 +58,7 @@ from build_tools.util import GetNumberOf
 from build_tools.util import GetRelPath
 from build_tools.util import IsLinux
 from build_tools.util import IsMac
+from build_tools.util import IsNetBSD
 from build_tools.util import IsWindows
 from build_tools.util import PrintErrorAndExit
 from build_tools.util import RemoveDirectoryRecursively
@@ -102,6 +103,7 @@ def GetBuildShortBaseName(target_platfor
       'Windows': 'out_win',
       'Mac': 'out_mac',
       'Linux': 'out_linux',
+      'NetBSD': 'out_bsd',
       'Android': 'out_android',
       'NaCl': 'out_nacl'
   }
@@ -179,6 +181,12 @@ def GetGypFileNames(options):
   elif options.target_platform == 'Android':
     # Add Android Mozc gyp scripts.
     gyp_file_names.extend(glob.glob('%s/android/*/*.gyp' % SRC_DIR))
+  elif options.target_platform == 'NetBSD':
+    gyp_file_names.extend(glob.glob('%s/unix/*/*.gyp' % SRC_DIR))
+    # Add ibus.gyp if ibus version is >=1.4.1.
+    if not PkgExists('ibus-1.0 >= 1.4.1'):
+      logging.info('removing ibus.gyp.')
+      gyp_file_names.remove('%s/unix/ibus/ibus.gyp' % SRC_DIR)
   gyp_file_names.sort()
   return gyp_file_names
 
@@ -243,6 +251,8 @@ def AddTargetPlatformOption(parser):
   # If you want Android build, specify "Android".
   if IsLinux():
     default_target = 'Linux'
+  if IsNetBSD():
+    default_target = 'NetBSD'
   elif IsWindows():
     default_target = 'Windows'
   elif IsMac():
@@ -410,6 +420,12 @@ def ExpandMetaTarget(options, meta_targe
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
     targets = [SRC_DIR + '/mac/mac.gyp:DiskImage']
   elif target_platform == 'Windows':
@@ -585,7 +601,8 @@ def GypMain(options, unused_args):
   if options.noqt or target_platform in ['Android', 'NaCl']:
     gyp_options.extend(['-D', 'use_qt=NO'])
     gyp_options.extend(['-D', 'qt_dir='])
-  elif target_platform == 'Linux':
+  elif (target_platform == 'Linux' or
+       target_platform == 'NetBSD'):
     gyp_options.extend(['-D', 'use_qt=YES'])
     gyp_options.extend(['-D', 'qt_dir='])
 
@@ -607,7 +624,8 @@ def GypMain(options, unused_args):
   else:
     gyp_options.extend(['-D', 'use_wix=NO'])
 
-  if target_platform == 'Linux':
+  if (target_platform == 'Linux' or
+       target_platform == 'NetBSD'): 
     gyp_options.extend(['-D', 'enable_gtk_renderer=1'])
 
   # Android
@@ -653,7 +671,8 @@ def GypMain(options, unused_args):
     gyp_options.extend(['-D', 'channel_dev=1'])
 
   def SetCommandLineForFeature(option_name, windows=False, mac=False,
-                               linux=False, android=False, nacl=False):
+                               linux=False, android=False, nacl=False,
+                               netbsd=False):
     """Updates an option like '--enable_foober' and add a -D argument for gyp.
 
     This function ensures an option like '--enable_foober' exists and it has a
@@ -675,6 +694,8 @@ def GypMain(options, unused_args):
           option on Android platform.
       nacl: A boolean which replesents the default value of the target
           option on NaCl.
+      netbsd: A boolean which replesents the default value of the target option
+          on NetBSD platform.
 
     Raises:
       ValueError: An error occurred when 'option_name' is empty.
@@ -685,6 +706,7 @@ def GypMain(options, unused_args):
     default_enabled = {'Windows': windows,
                        'Mac': mac,
                        'Linux': linux,
+                       'NetBSD': netbsd,
                        'Android': android,
                        'NaCl': nacl}.get(target_platform, False)
     enable_option_name = 'enable_%s' % option_name
@@ -697,6 +719,7 @@ def GypMain(options, unused_args):
 
   SetCommandLineForFeature(option_name='cloud_handwriting',
                            linux=is_official_dev,
+                           netbsd=is_official_dev,
                            windows=is_official_dev,
                            mac=is_official_dev)
 
@@ -706,7 +729,8 @@ def GypMain(options, unused_args):
   if IsWindows():
     gyp_options.extend(['-G', 'msvs_version=2015'])
 
-  if (target_platform == 'Linux' and
+  if ((target_platform == 'Linux' or
+       target_platform == 'NetBSD') and
       '%s/unix/ibus/ibus.gyp' % SRC_DIR in gyp_file_names):
     gyp_options.extend(['-D', 'use_libibus=1'])
 
@@ -1163,7 +1187,7 @@ def CleanMain(options, unused_args):
     if build_base:
       directory_names.append(build_base)
 
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     # Remove auto-generated files.
     file_names.append(os.path.join(SRC_DIR, 'android', 'AndroidManifest.xml'))
     file_names.append(os.path.join(
