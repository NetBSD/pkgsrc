$NetBSD: patch-protobuf_genproto.gypi,v 1.3 2013/09/07 18:42:14 ryoon Exp $

--- protobuf/genproto.gypi.orig	2013-08-28 05:26:13.000000000 +0000
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
