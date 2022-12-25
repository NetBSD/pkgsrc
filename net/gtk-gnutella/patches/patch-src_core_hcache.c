$NetBSD: patch-src_core_hcache.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/hcache.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/hcache.c
@@ -1878,7 +1878,7 @@ hcache_load_file(hostcache_t *hc, FILE *
 	g_return_if_fail(f);
 
 	now = tm_time();
-	while (fgets(ARYLEN(buffer), f)) {
+	while (fgets(buffer, sizeof(buffer), f)) {
 		const char *endptr;
 		host_addr_t addr;
 		uint16 port;
