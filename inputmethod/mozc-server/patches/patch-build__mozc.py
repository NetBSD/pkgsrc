$NetBSD: patch-build__mozc.py,v 1.4 2014/01/19 01:18:50 ryoon Exp $

--- build_mozc.py.orig	2014-01-06 07:10:26.000000000 +0000
+++ build_mozc.py
@@ -60,6 +60,7 @@ from build_tools.util import FindFileFro
 from build_tools.util import GetNumberOfProcessors
 from build_tools.util import GetRelPath
 from build_tools.util import IsLinux
+from build_tools.util import IsNetBSD
 from build_tools.util import IsMac
 from build_tools.util import IsWindows
 from build_tools.util import PrintErrorAndExit
@@ -120,6 +121,8 @@ def GetBuildBaseName(options, target_pla
     build_base = 'out_mac'
   elif target_platform == 'Linux':
     build_base = 'out_linux'
+  elif target_platform == 'NetBSD':
+    build_base = 'out_bsd'
   elif target_platform == 'Android':
     build_base = 'out_android'
   elif target_platform == 'NaCl':
@@ -214,6 +217,14 @@ def GetGypFileNames(options):
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
@@ -309,6 +320,8 @@ def AddTargetPlatformOption(parser):
   # If you want Android build, specify "Android".
   if IsLinux():
     default_target = 'Linux'
+  elif IsNetBSD():
+    default_target = 'NetBSD'
   elif IsWindows():
     default_target = 'Windows'
   elif IsMac():
@@ -506,6 +519,14 @@ def ExpandMetaTarget(options, meta_targe
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
@@ -531,7 +552,7 @@ def ParseBuildOptions(args=None, values=
   """Parses command line options for the build command."""
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -551,7 +572,7 @@ def ParseRunTestsOptions(args=None, valu
   parser = optparse.OptionParser(
       usage='Usage: %prog runtests [options] [test_targets] [-- build options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or ISNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -777,7 +798,8 @@ def GypMain(options, unused_args, _):
     gyp_options.extend(['-D', 'channel_dev=1'])
 
   def SetCommandLineForFeature(option_name, windows=False, mac=False,
-                               linux=False, android=False, nacl=False):
+                               linux=False, android=False, nacl=False,
+                               netbsd=False):
     """Updates an option like '--enable_foober' and add a -D argument for gyp.
 
     This function ensures an option like '--enable_foober' exists and it has a
@@ -799,6 +821,8 @@ def GypMain(options, unused_args, _):
           option on Android platform.
       nacl: A boolean which replesents the default value of the target
           option on NaCl.
+      netbsd:  boolean which replesents the default value of the target option
+	  on NetBSD platform.
 
     Raises:
       ValueError: An error occurred when 'option_name' is empty.
@@ -811,6 +835,7 @@ def GypMain(options, unused_args, _):
                        'Mac': mac,
                        'Linux': linux,
                        'Android': android,
+		       'NetBSD' : netbsd,
                        'NaCl': nacl}[options.target_platform]
     enable_option_name = 'enable_%s' % option_name
     enabled = options.ensure_value(enable_option_name, default_enabled)
@@ -822,10 +847,12 @@ def GypMain(options, unused_args, _):
 
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
@@ -863,7 +890,8 @@ def GypMain(options, unused_args, _):
   else:
     gyp_options.extend(['-D', 'use_zinnia=NO'])
 
-  if (options.target_platform == 'Linux' and
+  if ((options.target_platform == 'Linux' or
+       options.target_platform == 'NetBSD') and
       '%s/unix/ibus/ibus.gyp' % SRC_DIR in gyp_file_names):
     gyp_options.extend(['-D', 'use_libibus=1'])
 
@@ -896,7 +924,7 @@ def GypMain(options, unused_args, _):
   # command for pkg-config.  Here we catch the environment variable
   # and use the specified command instead of actual pkg-config
   # command.
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     gyp_options.extend(['-D', 'pkg_config_command=%s' % GetPkgConfigCommand()])
   else:
     gyp_options.extend(['-D', 'pkg_config_command='])
@@ -1049,6 +1077,41 @@ def BuildOnMac(options, targets, origina
               '-parallelizeTargets',
               'BUILD_WITH_GYP=1'])
 
+def BuildOnBSD(options, targets, unused_original_directory_name):
+  """Build the targets on *BSD."""
+  target_names = []
+  for target in targets:
+    (unused_gyp_file_name, target_name) = (
+        CanonicalTargetToGypFileAndTargetName(target))
+    target_names.append(target_name)
+
+    make_command = os.getenv('BUILD_COMMAND', 'make')
+
+  envvars = [
+      'CFLAGS',
+      'CXXFLAGS',
+      'CXX',
+      'CC',
+      'AR',
+      'AS',
+      'RANLIB',
+      'LD',
+  ]
+  for envvar in envvars:
+    if envvar in os.environ:
+      os.environ[envvar] = os.getenv(envvar)
+
+  # set output directory
+  os.environ['builddir_name'] = 'out_bsd'
+
+  build_args = ['-j%s' % options.jobs,
+                'MAKE_JOBS=%s' % options.jobs,
+                'BUILDTYPE=%s' % options.configuration]
+  build_args.append('builddir_name=%s' %
+                    GetBuildBaseName(options,
+                                     GetMozcVersion().GetTargetPlatform()))
+
+  RunOrDie([make_command] + build_args + target_names)
 
 def BuildOnWindows(targets):
   """Build the target on Windows."""
@@ -1076,6 +1139,8 @@ def BuildMain(options, targets, original
     BuildOnMac(options, targets, original_directory_name)
   elif IsLinux():
     BuildOnLinux(options, targets, original_directory_name)
+  elif IsNetBSD():
+    BuildOnBSD(options, targets, original_directory_name)
   elif IsWindows():
     BuildOnWindows(targets)
   else:
@@ -1341,7 +1406,7 @@ def CleanBuildFilesAndDirectories(option
     elif IsMac():
       directory_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                     '*.xcodeproj')))
-    elif IsLinux():
+    elif IsLinux() or IsNetBSD():
       file_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                '*.target.mk')))
       file_names.extend(glob.glob(os.path.join(gyp_directory_name,
