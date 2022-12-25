$NetBSD: patch-src_dht_routing.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/dht/routing.c.orig	2022-02-25 16:06:20.000000000 +0000
+++ src/dht/routing.c
@@ -5376,7 +5376,7 @@ dht_route_parse(FILE *f)
 	bit_array_init(tag_used, NUM_DHT_ROUTE_TAGS);
 	nodes = patricia_create(KUID_RAW_BITSIZE);
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		const char *tag_name, *value;
 		char *sp;
 		dht_route_tag_t tag;
