$NetBSD: patch-main.pro,v 1.1 2018/12/22 18:17:39 nia Exp $

Always use the builtin version of celt to avoid API incompatibilities.

--- main.pro.orig	2017-01-27 06:48:33.000000000 +0000
+++ main.pro
@@ -12,9 +12,6 @@ CONFIG *= ordered debug_and_release
   CONFIG(sbcelt) {
     SUBDIRS *= celt-0.7.0-build sbcelt-lib-build sbcelt-helper-build
   } else {
-    unix:!CONFIG(bundled-celt):system(pkg-config --atleast-version=0.7.0 celt) {
-      CONFIG *= no-bundled-celt
-    }
     !CONFIG(no-bundled-celt) {
       SUBDIRS *= celt-0.7.0-build celt-0.11.0-build
     }
