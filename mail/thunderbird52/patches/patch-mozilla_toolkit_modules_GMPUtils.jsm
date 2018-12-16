$NetBSD: patch-mozilla_toolkit_modules_GMPUtils.jsm,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/toolkit/modules/GMPUtils.jsm.orig	2017-04-14 04:53:29.000000000 +0000
+++ mozilla/toolkit/modules/GMPUtils.jsm
@@ -80,6 +80,7 @@ this.GMPUtils = {
       // Mac OSX, and Linux.
       return AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
              AppConstants.platform == "macosx" ||
+             AppConstants.platform == "netbsd" ||
              AppConstants.platform == "linux";
     }
 
