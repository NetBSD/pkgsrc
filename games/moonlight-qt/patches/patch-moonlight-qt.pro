$NetBSD: patch-moonlight-qt.pro,v 1.1 2023/02/16 08:06:21 charlotte Exp $

Skip the configure-time tests for SL and EGL

--- moonlight-qt.pro.orig	2022-05-24 17:41:37.000000000 -0700
+++ moonlight-qt.pro	2022-05-31 20:16:00.154248888 -0700
@@ -21,5 +21,3 @@
 
 # Run our compile tests
 load(configure)
-qtCompileTest(SL)
-qtCompileTest(EGL)
