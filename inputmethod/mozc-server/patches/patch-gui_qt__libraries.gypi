$NetBSD: patch-gui_qt__libraries.gypi,v 1.3 2014/06/15 13:08:34 ryoon Exp $

--- gui/qt_libraries.gypi.orig	2014-05-21 10:51:21.000000000 +0000
+++ gui/qt_libraries.gypi
@@ -84,7 +84,7 @@
         '$(SDKROOT)/System/Library/Frameworks/Carbon.framework',
       ]
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="netbsd"', {
       'conditions': [
         ['qt_dir', {
           'libraries': [
