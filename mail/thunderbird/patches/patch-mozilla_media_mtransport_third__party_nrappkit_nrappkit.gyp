$NetBSD: patch-mozilla_media_mtransport_third__party_nrappkit_nrappkit.gyp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/mtransport/third_party/nrappkit/nrappkit.gyp.orig	2013-10-23 22:09:11.000000000 +0000
+++ mozilla/media/mtransport/third_party/nrappkit/nrappkit.gyp
@@ -147,8 +147,18 @@
           ],
           
           'conditions' : [
-              ## Mac
+              ## Mac and BSDs
               [ 'OS == "mac"', {
+                'defines' : [
+                    'DARWIN',
+                ],
+              }],
+              [ 'os_bsd == 1', {
+                'defines' : [
+                    'BSD',
+                ],
+              }],
+              [ 'OS == "mac" or os_bsd == 1', {
                 'cflags_mozilla': [
                     '-Wall',
                     '-Wno-parentheses',
@@ -156,7 +166,6 @@
                     '-Wmissing-prototypes',
                  ],
                  'defines' : [
-                     'DARWIN',
                      'HAVE_LIBM=1',
                      'HAVE_STRDUP=1',
                      'HAVE_STRLCPY=1',
