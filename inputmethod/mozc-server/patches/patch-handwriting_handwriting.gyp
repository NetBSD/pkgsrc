$NetBSD: patch-handwriting_handwriting.gyp,v 1.3 2014/01/19 01:18:50 ryoon Exp $

--- handwriting/handwriting.gyp.orig	2014-01-06 07:10:31.000000000 +0000
+++ handwriting/handwriting.gyp
@@ -43,12 +43,12 @@
         'zinnia.gyp:zinnia',
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
