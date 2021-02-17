$NetBSD: patch-gui_qt__moc.gypi,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- gui/qt_moc.gypi.orig	2017-11-02 13:32:47.000000000 +0000
+++ gui/qt_moc.gypi
@@ -33,7 +33,7 @@
 
   'variables': {
     'conditions': [
-      ['target_platform=="Linux"', {
+      ['target_platform=="Linux" or target_platform=="NetBSD"', {
         'moc_path': '<!(pkg-config --variable=host_bins Qt5Core)/moc',
       }, 'qt_dir', {
         'moc_path': '<(qt_dir)/bin/moc<(EXECUTABLE_SUFFIX)',
