$NetBSD: patch-mozilla_media_webrtc_trunk_tools_gyp_pylib_gyp_generator_mozmake.py,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/webrtc/trunk/tools/gyp/pylib/gyp/generator/mozmake.py.orig	2013-10-23 22:09:12.000000000 +0000
+++ mozilla/media/webrtc/trunk/tools/gyp/pylib/gyp/generator/mozmake.py
@@ -6,6 +6,7 @@ import collections
 import gyp
 import gyp.common
 import sys
+import platform
 import os
 import re
 import shlex
@@ -113,20 +114,34 @@ def ensure_directory_exists(path):
 
 def GetFlavor(params):
   """Returns |params.flavor| if it's set, the system's default flavor else."""
+  system = platform.system().lower()
   flavors = {
-    'win32': 'win',
-    'darwin': 'mac',
-    'sunos5': 'solaris',
-    'freebsd7': 'freebsd',
-    'freebsd8': 'freebsd',
+    'microsoft': 'win',
+    'windows'  : 'win',
+    'darwin'   : 'mac',
+    'sunos'    : 'solaris',
+    'dragonfly': 'bsd',
+    'freebsd'  : 'bsd',
+    'netbsd'   : 'bsd',
+    'openbsd'  : 'bsd',
   }
-  flavor = flavors.get(sys.platform, 'linux')
-  return params.get('flavor', flavor)
+
+  if 'flavor' in params:
+    return params['flavor']
+  if system.startswith('cygwin'):
+    return 'win'
+  if system in flavors:
+    return flavors[system]
+
+  return 'linux'
 
 
 def CalculateVariables(default_variables, params):
+  flavor = GetFlavor(params)
+  if flavor == 'bsd':
+    flavor = platform.system().lower()
   generator_flags = params.get('generator_flags', {})
-  default_variables['OS'] = generator_flags.get('os', GetFlavor(params))
+  default_variables['OS'] = generator_flags.get('os', flavor)
 
 
 def CalculateGeneratorInputInfo(params):
