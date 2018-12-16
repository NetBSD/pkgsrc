$NetBSD: patch-mozilla_toolkit_mozapps_extensions_test_browser_browser__gmpProvider.js,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js.orig	2017-04-14 04:53:29.000000000 +0000
+++ mozilla/toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js
@@ -393,6 +393,7 @@ add_task(function* testEmeSupport() {
     } else if (addon.id == GMPScope.WIDEVINE_ID) {
       if (AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
           AppConstants.platform == "macosx" ||
+          AppConstants.platform == "netbsd" ||
           AppConstants.platform == "linux") {
         Assert.ok(item, "Widevine supported, found add-on element.");
       } else {
