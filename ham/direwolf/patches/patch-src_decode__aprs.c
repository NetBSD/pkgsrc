$NetBSD: patch-src_decode__aprs.c,v 1.1 2025/04/12 18:37:16 jmcneill Exp $

Fixup search locations for pkg PREFIX.

--- src/decode_aprs.c.orig	2025-04-12 12:38:21.806501733 +0000
+++ src/decode_aprs.c
@@ -4309,6 +4309,9 @@ static const char *search_locations[] = 
 	(const char *) "/usr/local/share/direwolf/tocalls.txt",
 	(const char *) "/usr/share/direwolf/tocalls.txt",
 #endif
+#ifdef INSTALL_PREFIX
+	(const char *) INSTALL_PREFIX "/share/direwolf/tocalls.txt",
+#endif
 #if __APPLE__
 	// https://groups.yahoo.com/neo/groups/direwolf_packet/conversations/messages/2458
 	// Adding the /opt/local tree since macports typically installs there.  Users might want their
