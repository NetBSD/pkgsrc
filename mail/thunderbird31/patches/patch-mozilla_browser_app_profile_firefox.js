$NetBSD: patch-mozilla_browser_app_profile_firefox.js,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/browser/app/profile/firefox.js.orig	2013-10-23 22:08:48.000000000 +0000
+++ mozilla/browser/app/profile/firefox.js
@@ -354,6 +354,7 @@ pref("browser.search.log", false);
 pref("browser.search.order.1",                "chrome://browser-region/locale/region.properties");
 pref("browser.search.order.2",                "chrome://browser-region/locale/region.properties");
 pref("browser.search.order.3",                "chrome://browser-region/locale/region.properties");
+pref("browser.search.order.4",                "chrome://browser-region/locale/region.properties");
 
 // search bar results always open in a new tab
 pref("browser.search.openintab", false);
