$NetBSD: patch-protobuf_protobuf.gyp,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- protobuf/protobuf.gyp.orig	2013-03-29 04:33:43.000000000 +0000
+++ protobuf/protobuf.gyp
@@ -140,7 +140,7 @@
           ],
           'conditions': [
             # for gcc and clang
-            ['OS=="linux" or OS=="mac"', {
+            ['OS=="linux" or OS=="mac" OS=="netbsd"', {
               'cflags': [
                 '-Wno-conversion-null',  # coded_stream.cc uses NULL to bool.
                 '-Wno-unused-function',
@@ -176,7 +176,7 @@
         '.',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'conditions': [
             ['use_libprotobuf!=1', {
               'cflags': [
@@ -212,7 +212,7 @@
       },
       'conditions': [
         # use system-installed protoc on Linux
-        ['OS!="linux"', {
+        ['OS!="linux" and OS!="netbsd"', {
           'includes' : [
             '../gyp/install_build_tool.gypi',
           ],
