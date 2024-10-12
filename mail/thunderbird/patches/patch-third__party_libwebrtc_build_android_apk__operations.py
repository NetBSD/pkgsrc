$NetBSD: patch-third__party_libwebrtc_build_android_apk__operations.py,v 1.1 2024/10/12 09:07:02 ryoon Exp $

Fix build with Python 3.13.

--- third_party/libwebrtc/build/android/apk_operations.py.orig	2024-10-11 13:43:36.953193495 +0000
+++ third_party/libwebrtc/build/android/apk_operations.py
@@ -13,7 +13,7 @@ import collections
 import json
 import logging
 import os
-import pipes
+import shlex
 import posixpath
 import random
 import re
@@ -294,7 +294,7 @@ def _RunGdb(device, package_name, debug_
     cmd.append('--verbose')
   if target_cpu:
     cmd.append('--target-arch=%s' % _TargetCpuToTargetArch(target_cpu))
-  logging.warning('Running: %s', ' '.join(pipes.quote(x) for x in cmd))
+  logging.warning('Running: %s', ' '.join(shlex.quote(x) for x in cmd))
   print(_Colorize('All subsequent output is from adb_gdb script.',
                   colorama.Fore.YELLOW))
   os.execv(gdb_script_path, cmd)
@@ -502,7 +502,7 @@ def _RunDiskUsage(devices, package_name)
               odex_paths.append('/data/dalvik-cache/%s@classes%s.dex' % (
                   mangled_apk_path, suffix))
 
-    odex_sizes = _DuHelper(d, ' '.join(pipes.quote(p) for p in odex_paths))
+    odex_sizes = _DuHelper(d, ' '.join(shlex.quote(p) for p in odex_paths))
 
     return (data_dir_sizes, code_cache_sizes, apk_sizes, lib_sizes, odex_sizes,
             compilation_filter)
@@ -1002,7 +1002,7 @@ def _DisplayArgs(devices, command_line_f
   print('Existing flags per-device (via /data/local/tmp/{}):'.format(
       command_line_flags_file))
   for flags in _PrintPerDeviceOutput(devices, outputs, single_line=True):
-    quoted_flags = ' '.join(pipes.quote(f) for f in flags)
+    quoted_flags = ' '.join(shlex.quote(f) for f in flags)
     print(quoted_flags or 'No flags set.')
 
 
