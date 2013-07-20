$NetBSD: patch-protobuf_genproto.gypi,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- protobuf/genproto.gypi.orig	2013-07-17 02:38:05.000000000 +0000
+++ protobuf/genproto.gypi
@@ -34,7 +34,7 @@
     'protoc_command': 'protoc<(EXECUTABLE_SUFFIX)',
   },
   'conditions': [
-    ['target_platform!="Linux"', {
+    ['target_platform!="Linux" and target_platform!="NetBSD"', {
       'variables': {
         'protoc_wrapper_additional_options': ['--protoc_dir=<(mozc_build_tools_dir)'],
       },
