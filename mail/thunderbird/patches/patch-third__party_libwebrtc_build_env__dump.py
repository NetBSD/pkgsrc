$NetBSD: patch-third__party_libwebrtc_build_env__dump.py,v 1.1 2024/10/12 09:07:02 ryoon Exp $

Fix build with Python 3.13.

--- third_party/libwebrtc/build/env_dump.py.orig	2024-10-11 13:43:22.427985012 +0000
+++ third_party/libwebrtc/build/env_dump.py
@@ -9,7 +9,7 @@
 import json
 import optparse
 import os
-import pipes
+import shlex
 import subprocess
 import sys
 
@@ -32,7 +32,7 @@ def main():
     if not options.output_json:
       parser.error('Requires --output-json option.')
 
-    envsetup_cmd = ' '.join(map(pipes.quote, args))
+    envsetup_cmd = ' '.join(map(shlex.quote, args))
     full_cmd = [
         'bash', '-c',
         '. %s > /dev/null; %s -d' % (envsetup_cmd, os.path.abspath(__file__))
