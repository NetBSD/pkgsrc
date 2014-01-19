$NetBSD: patch-protobuf_protobuf.gyp,v 1.3 2014/01/19 01:18:50 ryoon Exp $

--- protobuf/protobuf.gyp.orig	2014-01-06 07:10:31.000000000 +0000
+++ protobuf/protobuf.gyp
@@ -161,7 +161,7 @@
           ],
           'conditions': [
             # for gcc and clang
-            ['OS=="linux" or OS=="mac"', {
+            ['OS=="linux" or OS=="mac" or OS=="netbsd"', {
               'cflags': [
                 '-Wno-conversion-null',  # coded_stream.cc uses NULL to bool.
                 '-Wno-unused-function',
@@ -201,7 +201,7 @@
         '<(protobuf_root)/src',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'conditions': [
             ['use_libprotobuf!=1', {
               'cflags': [
@@ -237,7 +237,7 @@
       },
       'conditions': [
         # use system-installed protoc on Linux
-        ['OS!="linux"', {
+        ['OS!="linux" and OS!="netbsd"', {
           'includes' : [
             '../gyp/install_build_tool.gypi',
           ],
