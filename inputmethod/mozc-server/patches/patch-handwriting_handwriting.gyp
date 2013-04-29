$NetBSD: patch-handwriting_handwriting.gyp,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- handwriting/handwriting.gyp.orig	2013-03-29 04:33:25.000000000 +0000
+++ handwriting/handwriting.gyp
@@ -39,7 +39,7 @@
         '../base/base.gyp:base',
         '../gui/zinnia.gyp:zinnia',
       ],
-      'conditions': [['use_libzinnia==1 and OS=="linux"', {
+      'conditions': [['use_libzinnia==1 and (OS=="linux" or OS=="netbsd")', {
         'defines': [
           'USE_LIBZINNIA',
         ],
