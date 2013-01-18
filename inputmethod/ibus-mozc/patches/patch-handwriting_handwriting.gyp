$NetBSD: patch-handwriting_handwriting.gyp,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- handwriting/handwriting.gyp.orig	2012-08-31 05:37:06.000000000 +0000
+++ handwriting/handwriting.gyp
@@ -39,7 +39,7 @@
         '../base/base.gyp:base',
         '../gui/zinnia.gyp:zinnia',
       ],
-      'conditions': [['use_libzinnia==1 and OS=="linux"', {
+      'conditions': [['use_libzinnia==1 and OS=="linux" or OS=="netbsd"', {
         'defines': [
           'USE_LIBZINNIA',
         ],
