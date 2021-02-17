$NetBSD: patch-gui_qt__uic.gypi,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- gui/qt_uic.gypi.orig	2017-11-02 13:32:47.000000000 +0000
+++ gui/qt_uic.gypi
@@ -33,7 +33,7 @@
 
   'variables': {
     'conditions': [
-      ['target_platform=="Linux"', {
+      ['target_platform=="Linux" or target_platform=="NetBSD"', {
         'uic_path': '<!(pkg-config --variable=host_bins Qt5Core)/uic',
       }, 'qt_dir', {
         'uic_path': '<(qt_dir)/bin/uic<(EXECUTABLE_SUFFIX)',
