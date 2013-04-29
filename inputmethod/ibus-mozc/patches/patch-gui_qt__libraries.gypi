$NetBSD: patch-gui_qt__libraries.gypi,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- gui/qt_libraries.gypi.orig	2013-03-29 04:33:25.000000000 +0000
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
@@ -112,7 +112,7 @@
     # Workarounds related with clang.
     ['clang==1', {
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'cflags': [
             # Temporal workaround against following false warning in Clang.
             # http://lists.cs.uiuc.edu/pipermail/cfe-dev/2012-June/022477.html
