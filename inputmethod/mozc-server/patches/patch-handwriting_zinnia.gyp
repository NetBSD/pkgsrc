$NetBSD: patch-handwriting_zinnia.gyp,v 1.1 2014/01/19 01:18:50 ryoon Exp $

--- handwriting/zinnia.gyp.orig	2014-01-06 07:10:31.000000000 +0000
+++ handwriting/zinnia.gyp
@@ -48,7 +48,7 @@
         '-Wno-type-limits',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'conditions': [
             ['use_libzinnia==1', {
               'link_settings': {
