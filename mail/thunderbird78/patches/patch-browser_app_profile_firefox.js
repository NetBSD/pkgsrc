$NetBSD: patch-browser_app_profile_firefox.js,v 1.1 2023/02/05 08:32:24 he Exp $

--- browser/app/profile/firefox.js.orig	2020-08-28 21:32:23.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1921,6 +1921,12 @@ pref("fission.frontend.simulate-messages
 pref("toolkit.coverage.enabled", false);
 pref("toolkit.coverage.endpoint.base", "https://coverage.mozilla.org");
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Enable system addons, for example langpacks from www/firefox-l10n
+pref("extensions.autoDisableScopes", 11);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
