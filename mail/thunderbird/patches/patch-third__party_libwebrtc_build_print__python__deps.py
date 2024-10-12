$NetBSD: patch-third__party_libwebrtc_build_print__python__deps.py,v 1.1 2024/10/12 09:07:02 ryoon Exp $

Fix build with Python 3.13.

--- third_party/libwebrtc/build/print_python_deps.py.orig	2024-10-11 13:43:27.070262533 +0000
+++ third_party/libwebrtc/build/print_python_deps.py
@@ -14,7 +14,7 @@ This script should be compatible with Py
 import argparse
 import fnmatch
 import os
-import pipes
+import shlex
 import sys
 
 # Don't use any helper modules, or else they will end up in the results.
@@ -61,7 +61,7 @@ def _NormalizeCommandLine(options):
   for allowlist in sorted(options.allowlists):
     args.extend(('--allowlist', os.path.relpath(allowlist, _SRC_ROOT)))
   args.append(os.path.relpath(options.module, _SRC_ROOT))
-  return ' '.join(pipes.quote(x) for x in args)
+  return ' '.join(shlex.quote(x) for x in args)
 
 
 def _FindPythonInDirectory(directory, allow_test):
