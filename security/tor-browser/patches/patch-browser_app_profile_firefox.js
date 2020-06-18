$NetBSD: patch-browser_app_profile_firefox.js,v 1.3 2020/06/18 12:56:40 wiz Exp $

--- browser/app/profile/firefox.js.orig	2020-05-28 00:01:33.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1862,6 +1862,12 @@ pref("prio.publicKeyB", "26E6674E65425B8
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
