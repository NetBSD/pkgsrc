$NetBSD: patch-deps_v8_tools_gyp_v8.gyp,v 1.3 2015/09/09 00:04:54 ryoon Exp $

Fix path to Python.

--- deps/v8/tools/gyp/v8.gyp.orig	2015-09-08 15:30:44.000000000 +0000
+++ deps/v8/tools/gyp/v8.gyp
@@ -1696,14 +1696,14 @@
                       '<(PRODUCT_DIR)/natives_blob_host.bin',
                     ],
                     'action': [
-                      'python', '<@(_inputs)', '<(PRODUCT_DIR)/natives_blob_host.bin'
+                      '@PYTHONBIN@', '<@(_inputs)', '<(PRODUCT_DIR)/natives_blob_host.bin'
                     ],
                   }, {
                     'outputs': [
                       '<(PRODUCT_DIR)/natives_blob.bin',
                     ],
                     'action': [
-                      'python', '<@(_inputs)', '<(PRODUCT_DIR)/natives_blob.bin'
+                      '@PYTHONBIN@', '<@(_inputs)', '<(PRODUCT_DIR)/natives_blob.bin'
                     ],
                   }],
                 ],
@@ -1712,7 +1712,7 @@
                   '<(PRODUCT_DIR)/natives_blob.bin',
                 ],
                 'action': [
-                  'python', '<@(_inputs)', '<(PRODUCT_DIR)/natives_blob.bin'
+                  '@PYTHONBIN@', '<@(_inputs)', '<(PRODUCT_DIR)/natives_blob.bin'
                 ],
               }],
             ],
@@ -1812,7 +1812,7 @@
             '<(SHARED_INTERMEDIATE_DIR)/libraries.cc',
           ],
           'action': [
-            'python',
+            '@PYTHONBIN@',
             '../../tools/js2c.py',
             '<(SHARED_INTERMEDIATE_DIR)/libraries.cc',
             'CORE',
@@ -1838,7 +1838,7 @@
             '<(SHARED_INTERMEDIATE_DIR)/experimental-libraries.cc',
           ],
           'action': [
-            'python',
+            '@PYTHONBIN@',
             '../../tools/js2c.py',
             '<(SHARED_INTERMEDIATE_DIR)/experimental-libraries.cc',
             'EXPERIMENTAL',
@@ -1863,7 +1863,7 @@
             '<(SHARED_INTERMEDIATE_DIR)/extras-libraries.cc',
           ],
           'action': [
-            'python',
+            '@PYTHONBIN@',
             '../../tools/js2c.py',
             '<(SHARED_INTERMEDIATE_DIR)/extras-libraries.cc',
             'EXTRAS',
@@ -1900,7 +1900,7 @@
               '<(SHARED_INTERMEDIATE_DIR)/debug-support.cc',
             ],
             'action': [
-              'python',
+              '@PYTHONBIN@',
               '../../tools/gen-postmortem-metadata.py',
               '<@(_outputs)',
               '<@(heapobject_files)'
