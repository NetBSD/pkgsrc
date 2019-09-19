$NetBSD: patch-src_3rdparty_3rdparty.pro,v 1.1 2019/09/19 21:59:36 nia Exp $

Support building with "unsupported" Qt versions.

--- src/3rdparty/3rdparty.pro.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/3rdparty/3rdparty.pro
@@ -12,8 +12,8 @@ SUBDIRS = \
 }
 
 !r_mobile {
-    exists(qt-labs-qtscriptgenerator-$${QT_VERSION}) {
-        SUBDIRS += qt-labs-qtscriptgenerator-$${QT_VERSION}
+    exists(qt-labs-qtscriptgenerator-5.5.0) {
+        SUBDIRS += qt-labs-qtscriptgenerator-5.5.0
     }
     else {
         error("Script bindings not available for Qt version $${QT_VERSION}. You can add them to src/3rdparty/qt-labs-qtscriptgenerator-$${QT_VERSION} or use another version of Qt.")
