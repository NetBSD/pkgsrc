$NetBSD: patch-browser_app_profile_firefox.js,v 1.2 2020/03/13 17:59:27 wiz Exp $

--- browser/app/profile/firefox.js.orig	2019-07-06 01:48:29.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1865,6 +1865,15 @@ pref("prio.publicKeyB", "26E6674E65425B8
 pref("toolkit.coverage.enabled", false);
 pref("toolkit.coverage.endpoint.base", "https://coverage.mozilla.org");
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Enable system addons, for example langpacks from www/firefox-l10n
+pref("extensions.autoDisableScopes", 11);
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
