$NetBSD: patch-build__mozc.py,v 1.8 2016/05/16 11:51:49 ryoon Exp $

--- build_mozc.py.orig	2016-05-15 08:11:10.000000000 +0000
+++ build_mozc.py
@@ -58,6 +58,7 @@ from build_tools.util import GetNumberOf
 from build_tools.util import GetRelPath
 from build_tools.util import IsLinux
 from build_tools.util import IsMac
+from build_tools.util import IsNetBSD
 from build_tools.util import IsWindows
 from build_tools.util import PrintErrorAndExit
 from build_tools.util import RemoveDirectoryRecursively
@@ -123,6 +124,8 @@ def GetBuildShortBaseName(options, targe
     build_base = 'out_mac'
   elif target_platform == 'Linux':
     build_base = 'out_linux'
+  elif target_platform == 'NetBSD':
+    build_base = 'out_bsd'
   elif target_platform == 'Android':
     build_base = 'out_android'
   elif target_platform == 'NaCl':
@@ -223,6 +226,12 @@ def GetGypFileNames(options):
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
 
@@ -318,6 +327,8 @@ def AddTargetPlatformOption(parser):
   # If you want Android build, specify "Android".
   if IsLinux():
     default_target = 'Linux'
+  if IsNetBSD():
+    default_target = 'NetBSD'
   elif IsWindows():
     default_target = 'Windows'
   elif IsMac():
@@ -497,6 +508,12 @@ def ExpandMetaTarget(options, meta_targe
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
@@ -753,7 +770,8 @@ def GypMain(options, unused_args, _):
     gyp_options.extend(['-D', 'channel_dev=1'])
 
   def SetCommandLineForFeature(option_name, windows=False, mac=False,
-                               linux=False, android=False, nacl=False):
+                               linux=False, android=False, nacl=False,
+                               netbsd=False):
     """Updates an option like '--enable_foober' and add a -D argument for gyp.
 
     This function ensures an option like '--enable_foober' exists and it has a
@@ -775,6 +793,8 @@ def GypMain(options, unused_args, _):
           option on Android platform.
       nacl: A boolean which replesents the default value of the target
           option on NaCl.
+      netbsd: A boolean which replesents the default value of the target option
+          on NetBSD platform.
 
     Raises:
       ValueError: An error occurred when 'option_name' is empty.
@@ -786,6 +806,7 @@ def GypMain(options, unused_args, _):
     default_enabled = {'Windows': windows,
                        'Mac': mac,
                        'Linux': linux,
+                       'NetBSD': netbsd,
                        'Android': android,
                        'NaCl': nacl}[options.target_platform]
     enable_option_name = 'enable_%s' % option_name
@@ -798,6 +819,7 @@ def GypMain(options, unused_args, _):
 
   SetCommandLineForFeature(option_name='cloud_handwriting',
                            linux=is_official_dev,
+                           netbsd=is_official_dev,
                            windows=is_official_dev,
                            mac=is_official_dev)
 
@@ -825,7 +847,8 @@ def GypMain(options, unused_args, _):
   else:
     gyp_options.extend(['-D', 'use_dynamically_linked_qt=0'])
 
-  if (options.target_platform == 'Linux' and
+  if ((options.target_platform == 'Linux' or
+       options.target_platform == 'NetBSD') and
       '%s/unix/ibus/ibus.gyp' % SRC_DIR in gyp_file_names):
     gyp_options.extend(['-D', 'use_libibus=1'])
 
@@ -857,7 +880,7 @@ def GypMain(options, unused_args, _):
   # command for pkg-config.  Here we catch the environment variable
   # and use the specified command instead of actual pkg-config
   # command.
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     gyp_options.extend(['-D', 'pkg_config_command=%s' % GetPkgConfigCommand()])
   else:
     gyp_options.extend(['-D', 'pkg_config_command='])
@@ -1282,7 +1305,7 @@ def CleanBuildFilesAndDirectories(option
                                      GetMozcVersion().GetTargetPlatform())
   if target_platform:
     directory_names.append(target_platform)
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     # Remove auto-generated files.
     file_names.append(os.path.join(SRC_DIR, 'android', 'AndroidManifest.xml'))
     file_names.append(os.path.join(
