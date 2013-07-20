$NetBSD: patch-build__mozc.py,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- build_mozc.py.orig	2013-07-17 02:37:50.000000000 +0000
+++ build_mozc.py
@@ -62,6 +62,7 @@ from build_tools.util import GetRelPath
 from build_tools.util import IsLinux
 from build_tools.util import IsMac
 from build_tools.util import IsWindows
+from build_tools.util import IsNetBSD
 from build_tools.util import PrintErrorAndExit
 from build_tools.util import RemoveDirectoryRecursively
 from build_tools.util import RemoveFile
@@ -116,6 +117,8 @@ def GetBuildBaseName(options, target_pla
     build_base = 'out_mac'
   elif target_platform == 'Linux' or target_platform == 'ChromeOS':
     build_base = 'out_linux'
+  elif target_platform == 'NetBSD':
+    build_base = 'out_bsd'
   elif target_platform == 'Android':
     build_base = 'out_android'
   elif target_platform == 'NaCl':
@@ -219,6 +222,12 @@ def GetGypFileNames(options):
     if not PkgExists('ibus-1.0 >= 1.4.1'):
       logging.info('removing ibus.gyp.')
       gyp_file_names.remove('%s/unix/ibus/ibus.gyp' % SRC_DIR)
+  elif options.target_platform == 'NetBSD':
+    gyp_file_names.extend(glob.glob('%s/unix/*/*.gyp' % SRC_DIR))
+    # Add ibus.gyp if ibus version is >=1.4.1.
+    if not PkgExists('ibus-1.0 >= 1.4.1'):
+      logging.info('removing ibus.gyp.')
+      gyp_file_names.remove('%s/unix/ibus/ibus.gyp' % SRC_DIR)
   elif options.target_platform == 'ChromeOS':
     gyp_file_names.extend(glob.glob('%s/unix/ibus/*.gyp' % SRC_DIR))
   elif options.target_platform == 'NaCl':
@@ -266,6 +275,7 @@ def AddCommonOptions(parser):
                     help='Specifies the base directory of the built binaries.')
   parser.add_option('--language', dest='language', default='japanese',
                     help='Specify the target language to build.')
+  parser.add_option('--os', dest='os', default='linux')
   return parser
 
 
@@ -286,6 +296,8 @@ def AddTargetPlatformOption(parser):
   # If you want Android build, specify "Android".
   if IsLinux():
     default_target = 'Linux'
+  elif IsNetBSD():
+    default_target = 'NetBSD'
   elif IsWindows():
     default_target = 'Windows'
   elif IsMac():
@@ -490,6 +502,12 @@ def ExpandMetaTarget(options, meta_targe
                SRC_DIR + '/gui/gui.gyp:mozc_tool']
     if PkgExists('ibus-1.0 >= 1.4.1'):
       targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
+  elif target_platform == 'NetBSD':
+    targets = [SRC_DIR + '/server/server.gyp:mozc_server',
+               SRC_DIR + '/renderer/renderer.gyp:mozc_renderer',
+               SRC_DIR + '/gui/gui.gyp:mozc_tool']
+    if PkgExists('ibus-1.0 >= 1.4.1'):
+      targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
   elif target_platform == 'ChromeOS':
     targets.append(SRC_DIR + '/unix/ibus/ibus.gyp:ibus_mozc')
   elif target_platform == 'Mac':
@@ -517,7 +535,7 @@ def ParseBuildOptions(args=None, values=
   """Parses command line options for the build command."""
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -537,7 +555,7 @@ def ParseRunTestsOptions(args=None, valu
   parser = optparse.OptionParser(
       usage='Usage: %prog runtests [options] [test_targets] [-- build options]')
   AddCommonOptions(parser)
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     default_build_concurrency = GetNumberOfProcessors() * 2
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
@@ -705,6 +723,8 @@ def GypMain(options, unused_args):
     command_line.extend(['-D', 'wix_dir=%s' % options.wix_dir])
   else:
     command_line.extend(['-D', 'use_wix=NO'])
+  if options.os:
+    command_line.extend(['-D', 'OS=%s' % options.os])
 
   android_sdk_home = options.android_sdk_home
   if version.GetTargetPlatform() == 'Android':
@@ -767,7 +787,7 @@ def GypMain(options, unused_args):
 
   def SetCommandLineForFeature(option_name, windows=False, mac=False,
                                linux=False, chromeos=False, android=False,
-                               nacl=False):
+                               nacl=False, netbsd=False):
     """Updates an option like '--enable_foober' and add a -D argument for gyp.
 
     This function ensures an option like '--enable_foober' exists and it has a
@@ -791,6 +811,8 @@ def GypMain(options, unused_args):
           option on Android platform.
       nacl: A boolean which replesents the default value of the target
           option on NaCl.
+      netbsd:  boolean which replesents the default value of the target option
+          on NetBSD platform.
 
     Raises:
       ValueError: An error occurred when 'option_name' is empty.
@@ -804,6 +826,7 @@ def GypMain(options, unused_args):
                        'Linux': linux,
                        'ChromeOS': chromeos,
                        'Android': android,
+                       'NetBSD' : netbsd,
                        'NaCl': nacl}[options.target_platform]
     enable_option_name = 'enable_%s' % option_name
     enabled = options.ensure_value(enable_option_name, default_enabled)
@@ -820,15 +843,18 @@ def GypMain(options, unused_args):
   SetCommandLineForFeature(option_name='webservice_infolist')
   SetCommandLineForFeature(option_name='cloud_sync',
                            linux=is_official_dev,
+                           netbsd=is_official_dev,
                            windows=is_official_dev,
                            mac=is_official_dev,
                            nacl=is_official_dev)
   SetCommandLineForFeature(option_name='cloud_handwriting',
                            linux=is_official_dev,
+                           netbsd=is_official_dev,
                            windows=is_official_dev,
                            mac=is_official_dev)
   SetCommandLineForFeature(option_name='http_client',
                            linux=is_official,
+                           netbsd=is_official,
                            windows=is_official,
                            mac=is_official,
                            chromeos=False,  # not supported.
@@ -872,7 +898,8 @@ def GypMain(options, unused_args):
     command_line.extend(['-D', 'use_zinnia=NO'])
 
   if ((options.target_platform == 'Linux' or
-       options.target_platform == 'ChromeOS') and
+       options.target_platform == 'ChromeOS' or
+       options.target_platform == 'NetBSD') and
       '%s/unix/ibus/ibus.gyp' % SRC_DIR in gyp_file_names):
     command_line.extend(['-D', 'use_libibus=1'])
 
@@ -917,7 +944,7 @@ def GypMain(options, unused_args):
   # command for pkg-config.  Here we catch the environment variable
   # and use the specified command instead of actual pkg-config
   # command.
-  if IsLinux():
+  if IsLinux() or IsNetBSD():
     command_line.extend(['-D', 'pkg_config_command=%s' % GetPkgConfigCommand()])
   else:
     command_line.extend(['-D', 'pkg_config_command='])
@@ -1082,6 +1109,41 @@ def BuildOnMac(options, targets, origina
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
@@ -1112,6 +1174,8 @@ def BuildMain(options, targets, original
     BuildOnMac(options, targets, original_directory_name)
   elif IsLinux():
     BuildOnLinux(options, targets, original_directory_name)
+  elif IsNetBSD():
+    BuildOnBSD(options, targets, original_directory_name)
   elif IsWindows():
     BuildOnWindows(targets)
   else:
@@ -1388,7 +1452,7 @@ def CleanBuildFilesAndDirectories(option
     elif IsMac():
       directory_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                     '*.xcodeproj')))
-    elif IsLinux():
+    elif IsLinux() or IsNetBSD():
       file_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                '*.target.mk')))
       file_names.extend(glob.glob(os.path.join(gyp_directory_name,
@@ -1436,6 +1500,9 @@ def CleanBuildFilesAndDirectories(option
 
   elif IsWindows():
     file_names.append('third_party/breakpad/breakpad.gyp')
+  elif IsNetBSD():
+    file_names.append('Makefile')
+    directory_names.append('out_bsd')
   # Remove files.
   for file_name in file_names:
     RemoveFile(file_name)
