$NetBSD: patch-protobuf_protobuf.gyp,v 1.5 2015/01/06 10:30:54 ryoon Exp $

--- protobuf/protobuf.gyp.orig	2015-01-06 06:21:18.000000000 +0000
+++ protobuf/protobuf.gyp
@@ -254,7 +254,7 @@
       },
       'conditions': [
         # use system-installed protoc on Linux
-        ['OS!="linux"', {
+        ['OS!="linux" and OS!="netbsd"', {
           'includes' : [
             '../gyp/install_build_tool.gypi',
           ],
