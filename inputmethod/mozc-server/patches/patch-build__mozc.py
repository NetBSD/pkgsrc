$NetBSD: patch-build__mozc.py,v 1.5 2014/07/19 09:03:04 ryoon Exp $

--- build_mozc.py.orig	2014-07-14 10:14:21.000000000 +0000
+++ build_mozc.py
@@ -60,6 +60,7 @@ from build_tools.util import FindFileFro
 from build_tools.util import GetNumberOfProcessors
 from build_tools.util import GetRelPath
 from build_tools.util import IsLinux
+from build_tools.util import IsNetBSD
 from build_tools.util import IsMac
 from build_tools.util import IsWindows
 from build_tools.util import PrintErrorAndExit
@@ -121,6 +122,8 @@ def GetBuildShortBaseName(options, targe
     build_base = 'out_mac'
   elif target_platform == 'Linux':
     build_base = 'out_linux'
+  elif target_platform == 'NetBSD':
+    build_base = 'out_bsd'
   elif target_platform == 'Android':
     build_base = 'out_android'
   elif target_platform == 'NaCl':
@@ -220,6 +223,14 @@ def GetGypFileNames(options):
     if not PkgExists('ibus-1.0 >= 1.4.1'):
       logging.info('removing ibus.gyp.')
       gyp_file_names.remove('%s/unix/ibus/ibus.gyp' % SRC_DIR)
+  elif options.target_platform == 'NetBSD':
+    gyp_file_names.extend(glob.glob('%s/unix/*/*.gyp' % SRC_DIR))
+    # Add ibus.gyp if ibus version is >=1.4.1.
+    if not PkgExists('ibus-1.0 >= 1.4.1'):
+      logging.info('removing ibus.gyp.')
+      gyp_file_names.remove('%s/unix/ibus/ibus.gyp' % SRC_DIR)
+  elif options.target_platform == 'ChromeOS':
+    gyp_file_names.extend(glob.glob('%s/unix/ibus/*.gyp' % SRC_DIR))
   elif options.target_platform == 'NaCl':
     # Add chrome NaCl Mozc gyp scripts.
     gyp_file_names.append('%s/chrome/nacl/nacl_extension.gyp' % SRC_DIR)
@@ -315,6 +326,8 @@ def AddTargetPlatformOption(parser):
   # If you want Android build, specify "Android".
   if IsLinux():
     default_target = 'Linux'
+  elif IsNetBSD():
+    default_target = 'NetBSD'
   elif IsWindows():
     default_target = 'Windows'
   elif IsMac():
@@ -512,6 +525,14 @@ def ExpandMetaTarget(options, meta_targe
                SRC_DIR + '/gui/gui.gyp:mozc_tool']
     if PkgExists('ibus-1.0 >= 1.4.1'):
       targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
+  elif target_platform == 'NetBSD':
+    targets = [SRC_DIR + '/server/server.gyp:mozc_server',
+               SRC_DIR + '/renderer/renderer.gyp:mozc_renderer',
+               SRC_DIR + '/gui/gui.gyp:mozc_tool']
+    if PkgExists('ibus-1.0 >= 1.4.1'):
+      targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
+  elif target_platform == 'ChromeOS':
+    targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
   elif target_platform == 'Mac':
     targets = [SRC_DIR + '/mac/mac.gyp:DiskImage']
   elif target_platform == 'Windows':
@@ -537,7 +558,7 @@ def ParseBuildOptions(args=None, values=
   """Parses command line options for the build command."""
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -566,7 +587,7 @@ def ParseRunTestsOptions(args=None, valu
   parser = optparse.OptionParser(
       usage='Usage: %prog runtests [options] [test_targets] [-- build options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or ISNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -787,7 +808,8 @@ def GypMain(options, unused_args, _):
     gyp_options.extend(['-D', 'channel_dev=1'])
 
   def SetCommandLineForFeature(option_name, windows=False, mac=False,
-                               linux=False, android=False, nacl=False):
+                               linux=False, android=False, nacl=False,
+                               netbsd=False):
     """Updates an option like '--enable_foober' and add a -D argument for gyp.
 
     This function ensures an option like '--enable_foober' exists and it has a
@@ -809,6 +831,8 @@ def GypMain(options, unused_args, _):
           option on Android platform.
       nacl: A boolean which replesents the default value of the target
           option on NaCl.
+      netbsd:  boolean which replesents the default value of the target option
+	  on NetBSD platform.
 
     Raises:
       ValueError: An error occurred when 'option_name' is empty.
@@ -821,6 +845,7 @@ def GypMain(options, unused_args, _):
                        'Mac': mac,
                        'Linux': linux,
                        'Android': android,
+		       'NetBSD' : netbsd,
                        'NaCl': nacl}[options.target_platform]
     enable_option_name = 'enable_%s' % option_name
     enabled = options.ensure_value(enable_option_name, default_enabled)
@@ -832,10 +857,12 @@ def GypMain(options, unused_args, _):
 
   SetCommandLineForFeature(option_name='cloud_handwriting',
                            linux=is_official_dev,
+			   netbsd=is_official_dev,
                            windows=is_official_dev,
                            mac=is_official_dev)
   SetCommandLineForFeature(option_name='http_client',
                            linux=is_official,
+			   netbsd=is_official,
                            windows=is_official,
                            mac=is_official,
                            android=is_official,
@@ -873,7 +900,8 @@ def GypMain(options, unused_args, _):
   else:
     gyp_options.extend(['-D', 'use_zinnia=NO'])
 
-  if (options.target_platform == 'Linux' and
+  if ((options.target_platform == 'Linux' or
+       options.target_platform == 'NetBSD') and
       '%s/unix/ibus/ibus.gyp' % SRC_DIR in gyp_file_names):
     gyp_options.extend(['-D', 'use_libibus=1'])
 
@@ -906,7 +934,7 @@ def GypMain(options, unused_args, _):
   # command for pkg-config.  Here we catch the environment variable
   # and use the specified command instead of actual pkg-config
   # command.
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     gyp_options.extend(['-D', 'pkg_config_command=%s' % GetPkgConfigCommand()])
   else:
     gyp_options.extend(['-D', 'pkg_config_command='])
@@ -1050,6 +1078,25 @@ def BuildOnMac(options, targets, origina
               '-parallelizeTargets',
               'BUILD_WITH_GYP=1'])
 
+def BuildOnBSD(options, targets, unused_original_directory_name):
+  """Build the targets on BSD."""
+  target_names = []
+  for target in targets:
+    (unused_gyp_file_name, target_name) = (
+        CanonicalTargetToGypFileAndTargetName(target))
+    target_names.append(target_name)
+
+  ninja = 'ninja'
+  if hasattr(options, 'android_device'):
+    # Only for android testing.
+    os.environ['ANDROID_DEVICES'] = options.android_device
+
+  short_basename =  GetBuildShortBaseName(options,
+                                          GetMozcVersion().GetTargetPlatform())
+  make_command = ninja
+  build_args = ['-j %s' % options.jobs,
+                '-C', '%s/%s' % (short_basename, options.configuration)]
+  RunOrDie([make_command] + build_args + target_names)
 
 def BuildOnWindows(targets):
   """Build the target on Windows."""
@@ -1077,6 +1124,8 @@ def BuildMain(options, targets, original
     BuildOnMac(options, targets, original_directory_name)
   elif IsLinux():
     BuildOnLinux(options, targets, original_directory_name)
+  elif IsNetBSD():
+    BuildOnBSD(options, targets, original_directory_name)
   elif IsWindows():
     BuildOnWindows(targets)
   else:
