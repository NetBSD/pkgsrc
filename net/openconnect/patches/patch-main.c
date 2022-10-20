$NetBSD: patch-main.c,v 1.1 2022/10/20 19:12:57 schmonz Exp $

Define environ before it's used. Fixes build on at least NetBSD.

--- main.c.orig	2022-04-29 15:36:04.000000000 +0000
+++ main.c
@@ -899,6 +899,8 @@ static BOOL WINAPI console_ctrl_handler(
 #endif
 
 #ifdef HAVE_POSIX_SPAWN
+extern char **environ;
+
 static int spawn_browser(struct openconnect_info *vpninfo, const char *url, void *cbdata)
 {
 	vpn_progress(vpninfo, PRG_TRACE,
