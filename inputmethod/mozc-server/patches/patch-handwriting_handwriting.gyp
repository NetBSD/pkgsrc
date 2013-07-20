$NetBSD: patch-handwriting_handwriting.gyp,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- handwriting/handwriting.gyp.orig	2013-07-17 02:38:04.000000000 +0000
+++ handwriting/handwriting.gyp
@@ -43,12 +43,12 @@
         '../gui/zinnia.gyp:zinnia',
       ],
       'conditions': [
-        ['target_platform=="Linux" and use_libzinnia==1', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and use_libzinnia==1', {
           'defines': [
             'USE_LIBZINNIA',
           ],
         }],
-        ['target_platform=="Linux" and use_libzinnia==1 and zinnia_model_file!=""', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and use_libzinnia==1 and zinnia_model_file!=""', {
           'defines': [
             'MOZC_ZINNIA_MODEL_FILE="<(zinnia_model_file)"',
           ],
