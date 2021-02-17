$NetBSD: patch-gui_qt__rcc.gypi,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- gui/qt_rcc.gypi.orig	2017-11-02 13:32:47.000000000 +0000
+++ gui/qt_rcc.gypi
@@ -33,7 +33,7 @@
 
   'variables': {
     'conditions': [
-      ['target_platform=="Linux"', {
+      ['target_platform=="Linux" or target_platform=="NetBSD"', {
         'rcc_path': '<!(pkg-config --variable=host_bins Qt5Core)/rcc',
       }, 'qt_dir', {
         'rcc_path': '<(qt_dir)/bin/rcc<(EXECUTABLE_SUFFIX)',
