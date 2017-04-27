$NetBSD: patch-mozilla_toolkit_modules_GMPUtils.jsm,v 1.3 2017/04/27 13:32:41 ryoon Exp $

--- mozilla/toolkit/modules/GMPUtils.jsm.orig	2017-04-14 04:53:29.000000000 +0000
+++ mozilla/toolkit/modules/GMPUtils.jsm
@@ -80,6 +80,7 @@ this.GMPUtils = {
       // Mac OSX, and Linux.
       return AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
              AppConstants.platform == "macosx" ||
+             AppConstants.platform == "netbsd" ||
              AppConstants.platform == "linux";
     }
 
