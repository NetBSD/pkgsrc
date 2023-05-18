$NetBSD: patch-hpke.c,v 1.1 2023/05/18 13:55:54 schmonz Exp $

Define environ before it's used. Fixes build on at least NetBSD.

--- hpke.c.orig	2023-05-17 11:27:35.000000000 +0000
+++ hpke.c
@@ -53,6 +53,8 @@ static const char response_200[] =
 	"<html><title>Success</title><body>Success</body></html>\r\n";
 
 #ifdef HAVE_POSIX_SPAWN
+extern char **environ;
+
 static int spawn_browser(struct openconnect_info *vpninfo)
 {
 	vpn_progress(vpninfo, PRG_TRACE, _("Spawning external browser '%s'\n"),
