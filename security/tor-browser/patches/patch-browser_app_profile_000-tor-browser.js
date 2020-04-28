$NetBSD: patch-browser_app_profile_000-tor-browser.js,v 1.1 2020/04/28 19:38:49 wiz Exp $

Despite the warning at the top of this file, we change the default for the socks
port in pkgsrc from 9150 to 9050.

9150 is used for distributions where tor is bundled with tor-browser, so the
standard port can't be used because another tor may already be running there.

pkgsrc's tor-browser uses the system-wide installation of tor and thus should use
its default port to minimize manual setup steps for the end users.

--- browser/app/profile/000-tor-browser.js.orig	2020-04-04 03:09:31.000000000 +0000
+++ browser/app/profile/000-tor-browser.js
@@ -161,7 +161,7 @@ pref("network.predictor.enabled", false)
 
 // Proxy and proxy security
 pref("network.proxy.socks", "127.0.0.1");
-pref("network.proxy.socks_port", 9150);
+pref("network.proxy.socks_port", 9050);
 pref("network.proxy.socks_remote_dns", true);
 pref("network.proxy.no_proxies_on", ""); // For fingerprinting and local service vulns (#10419)
 pref("network.proxy.allow_hijacking_localhost", true); // Allow proxies for localhost (#31065)
