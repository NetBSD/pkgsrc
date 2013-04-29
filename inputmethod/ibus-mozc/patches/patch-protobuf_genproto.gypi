$NetBSD: patch-protobuf_genproto.gypi,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- protobuf/genproto.gypi.orig	2013-03-29 04:33:43.000000000 +0000
+++ protobuf/genproto.gypi
@@ -33,19 +33,19 @@
     'wrapper_path': '<(DEPTH)/build_tools/protoc_wrapper.py',
   },
   'conditions': [
-    ['target_platform!="linux"', {
+    ['target_platform!="Linux" and target_platform!="NetBSD"', {
       'variables': {
-        'protoc_command%': '<(mozc_build_tools_dir)/protoc<(EXECUTABLE_SUFFIX)',
+        'protoc_command%': '@PREFIX@/bin/protoc<(EXECUTABLE_SUFFIX)',
       },
     }, {  # else
       'conditions': [
         ['use_libprotobuf==0', {
           'variables': {
-            'protoc_command%': '<(mozc_build_tools_dir)/protoc<(EXECUTABLE_SUFFIX)',
+            'protoc_command%': '@PREFIX@/bin/protoc<(EXECUTABLE_SUFFIX)',
           },
         }, {  # else
           'variables': {
-            'protoc_command%': 'protoc<(EXECUTABLE_SUFFIX)',
+            'protoc_command%': '@PREFIX@/bin/protoc<(EXECUTABLE_SUFFIX)',
           },
         }],
       ],
