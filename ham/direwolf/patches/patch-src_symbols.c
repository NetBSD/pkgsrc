$NetBSD: patch-src_symbols.c,v 1.1 2025/04/12 18:37:16 jmcneill Exp $

Fixup search locations for pkg PREFIX.

--- src/symbols.c.orig	2025-04-12 12:37:35.269157776 +0000
+++ src/symbols.c
@@ -271,6 +271,9 @@ static const char *search_locations[] = 
 	(const char *) "/usr/local/share/direwolf/symbols-new.txt",
 	(const char *) "/usr/share/direwolf/symbols-new.txt",
 #endif
+#ifdef INSTALL_PREFIX
+	(const char *) INSTALL_PREFIX "/share/direwolf/symbols-new.txt",
+#endif
 #if __APPLE__
 	// https://groups.yahoo.com/neo/groups/direwolf_packet/conversations/messages/2458
 	// Adding the /opt/local tree since macports typically installs there.  Users might want their
