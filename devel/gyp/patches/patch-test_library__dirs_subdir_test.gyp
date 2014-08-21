$NetBSD: patch-test_library__dirs_subdir_test.gyp,v 1.1 2014/08/21 14:49:43 he Exp $

Treat NetBSD as Linux in this test.

--- test/library_dirs/subdir/test.gyp.orig	2014-07-14 14:19:49.000000000 +0000
+++ test/library_dirs/subdir/test.gyp
@@ -52,7 +52,7 @@
       ],
       'link_settings': {
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'libraries': [
               '-lmylib',
             ],
