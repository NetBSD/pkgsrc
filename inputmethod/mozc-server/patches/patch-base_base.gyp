$NetBSD: patch-base_base.gyp,v 1.4 2014/07/19 09:03:04 ryoon Exp $

--- base/base.gyp.orig	2014-07-06 07:03:03.000000000 +0000
+++ base/base.gyp
@@ -78,7 +78,7 @@
         # shared among *host* binaries and *target* binaries. This means that
         # you should implement *host* binaries by using limited libraries
         # which are also available on NDK.
-        ['OS=="linux" and target_platform!="Android" and '
+        ['OS=="netbsd" or (OS=="linux" and target_platform!="Android") and '
          'not (target_platform=="NaCl" and _toolset=="target")', {
           'defines': [
             'HAVE_LIBRT=1',
