$NetBSD: patch-browser_app_profile_000-tor-browser.js,v 1.2 2020/05/01 07:01:46 wiz Exp $

First chunk:

Despite the warning at the top of this file, we change the default for the socks
port in pkgsrc from 9150 to 9050.

9150 is used for distributions where tor is bundled with tor-browser, so the
standard port can't be used because another tor may already be running there.

pkgsrc's tor-browser uses the system-wide installation of tor and thus should use
its default port to minimize manual setup steps for the end users.


Second chunk:
Hardcode font list on all pkgsrc platforms to make it harder to fingerprint.

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
@@ -370,7 +370,7 @@ pref("font.name.sans-serif.ar", "Arial")
 pref("font.system.whitelist", "Arial, Batang, 바탕, Cambria Math, Courier New, Euphemia, Gautami, Georgia, Gulim, 굴림, GulimChe, 굴림체, Iskoola Pota, Kalinga, Kartika, Latha, Lucida Console, MS Gothic, ＭＳ ゴシック, MS Mincho, ＭＳ 明朝, MS PGothic, ＭＳ Ｐゴシック, MS PMincho, ＭＳ Ｐ明朝, MV Boli, Malgun Gothic, Mangal, Meiryo, Meiryo UI, Microsoft Himalaya, Microsoft JhengHei, Microsoft JhengHei UI, Microsoft YaHei, 微软雅黑, Microsoft YaHei UI, MingLiU, 細明體, Noto Sans Buginese, Noto Sans Khmer, Noto Sans Lao, Noto Sans Myanmar, Noto Sans Yi, Nyala, PMingLiU, 新細明體, Plantagenet Cherokee, Raavi, Segoe UI, Shruti, SimSun, 宋体, Sylfaen, Tahoma, Times New Roman, Tunga, Verdana, Vrinda, Yu Gothic UI");
 #endif
 
-#ifdef XP_LINUX
+#if 1
 pref("font.default.lo", "Noto Sans Lao");
 pref("font.default.my", "Noto Sans Myanmar");
 pref("font.default.x-western", "sans-serif");
