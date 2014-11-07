$NetBSD: patch-base_base.gyp,v 1.5 2014/11/07 23:28:36 ryoon Exp $

--- base/base.gyp.orig	2014-11-03 05:13:02.000000000 +0000
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
