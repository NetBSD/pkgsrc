$NetBSD: patch-deps_v8_tools_gyp_v8.gyp,v 1.1 2013/05/22 15:17:07 mspo Exp $

Fix path to Python.

--- deps/v8/tools/gyp/v8.gyp.orig	2012-06-11 16:30:44.000000000 +0000
+++ deps/v8/tools/gyp/v8.gyp
@@ -796,7 +796,7 @@
                 '<(SHARED_INTERMEDIATE_DIR)/libraries.cc',
               ],
               'action': [
-                'python',
+                '@PYTHONBIN@',
                 '../../tools/js2c.py',
                 '<@(_outputs)',
                 'CORE',
@@ -814,7 +814,7 @@
                 '<(SHARED_INTERMEDIATE_DIR)/experimental-libraries.cc',
               ],
               'action': [
-                'python',
+                '@PYTHONBIN@',
                 '../../tools/js2c.py',
                 '<@(_outputs)',
                 'EXPERIMENTAL',
@@ -844,7 +844,7 @@
                   '<(SHARED_INTERMEDIATE_DIR)/debug-support.cc',
                 ],
                 'action': [
-                  'python',
+                  '@PYTHONBIN@',
                   '../../tools/gen-postmortem-metadata.py',
                   '<@(_outputs)',
                   '<@(heapobject_files)'
