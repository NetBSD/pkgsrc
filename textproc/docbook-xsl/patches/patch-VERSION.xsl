$NetBSD: patch-VERSION.xsl,v 1.1 2022/06/04 13:22:15 wiz Exp $

Fix version string.

--- VERSION.xsl.orig	2016-12-09 22:47:32.000000000 +0000
+++ VERSION.xsl
@@ -26,7 +26,7 @@
   <fm:Branch>XSL Stylesheets</fm:Branch>
   <!-- * set/keep fm:version as N.NN.N-pre except for official releases, -->
   <!-- * then after the release, revert it to N.NN.N-pre & check back in -->
-  <fm:Version>snapshot</fm:Version>
+  <fm:Version>1.79.2</fm:Version>
 <!--
   <fm:License>MIT/X Consortium License</fm:License>
 -->
