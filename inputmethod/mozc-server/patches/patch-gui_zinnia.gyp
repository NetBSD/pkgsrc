$NetBSD: patch-gui_zinnia.gyp,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- gui/zinnia.gyp.orig	2012-08-31 05:36:43.000000000 +0000
+++ gui/zinnia.gyp
@@ -48,7 +48,7 @@
         '-Wno-type-limits',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'conditions': [
             ['use_libzinnia==1', {
               'link_settings': {
