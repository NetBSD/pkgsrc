$NetBSD: patch-browser_app_profile_firefox.js,v 1.1 2018/12/16 08:12:15 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2018-12-04 23:11:44.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1748,3 +1748,9 @@ pref("app.shield.optoutstudies.enabled",
 #else
 pref("app.shield.optoutstudies.enabled", false);
 #endif
+
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
