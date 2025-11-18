$NetBSD: patch-plugins_wpg_plugin.m4,v 1.1 2025/11/18 17:26:21 nia Exp $

Fix version numbers for current reality of dependencies.

--- plugins/wpg/plugin.m4.orig	2025-11-16 16:00:48.701317790 +0000
+++ plugins/wpg/plugin.m4
@@ -1,5 +1,5 @@
 
-wpg_pkgs="$gsf_req libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0"
+wpg_pkgs="$gsf_req libwpg-0.3 >= 0 libwpd-0.10 >= 0"
 wpg_deps="no"
 
 if test "$enable_wpg" != ""; then
