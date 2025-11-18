$NetBSD: patch-plugins_wordperfect_plugin.m4,v 1.1 2025/11/18 17:26:21 nia Exp $

Fix version numbers for current reality of dependencies.

--- plugins/wordperfect/plugin.m4.orig	2025-11-16 16:17:25.572834946 +0000
+++ plugins/wordperfect/plugin.m4
@@ -1,6 +1,6 @@
 
-wordperfect_pkgs="libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0 $gsf_req"
-wordperfect_wps_pkgs='libwps-0.2 >= 0.1.0'
+wordperfect_pkgs="libwpg-0.3 >= 0.3.0 libwpd-0.10 >= 0.10.0 $gsf_req"
+wordperfect_wps_pkgs='libwps-0.4 >= 0.4.0'
 wordperfect_deps="no"
 
 WORDPERFECT_CFLAGS=
