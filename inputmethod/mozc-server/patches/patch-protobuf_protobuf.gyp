$NetBSD: patch-protobuf_protobuf.gyp,v 1.4 2014/06/15 13:08:34 ryoon Exp $

--- protobuf/protobuf.gyp.orig	2014-05-21 10:49:57.000000000 +0000
+++ protobuf/protobuf.gyp
@@ -211,7 +211,7 @@
         '<(protobuf_root)/src',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'conditions': [
             ['use_libprotobuf!=1', {
               'cflags': [
@@ -247,7 +247,7 @@
       },
       'conditions': [
         # use system-installed protoc on Linux
-        ['OS!="linux"', {
+        ['OS!="linux" and OS!="netbsd"', {
           'includes' : [
             '../gyp/install_build_tool.gypi',
           ],
