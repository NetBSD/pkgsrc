$NetBSD: patch-protobuf_protobuf.gyp,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- protobuf/protobuf.gyp.orig	2012-08-31 05:37:07.000000000 +0000
+++ protobuf/protobuf.gyp
@@ -138,7 +138,7 @@
           },
           'conditions': [
             # for gcc and clang
-            ['OS=="linux" or OS=="mac"', {
+            ['OS=="linux" or OS=="mac" or OS="netbsd"', {
               'cflags': [
                 '-Wno-conversion-null',  # coded_stream.cc uses NULL to bool.
                 '-Wno-unused-function',
@@ -159,7 +159,7 @@
         '.',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'conditions': [
             ['use_libprotobuf!=1', {
               'cflags': [
@@ -196,7 +196,7 @@
       },
       'conditions': [
         # use system-installed protoc on Linux
-        ['OS!="linux"', {
+        ['OS!="linux" and OS!="netbsd"', {
           'includes' : [
             '../gyp/install_build_tool.gypi',
           ],
