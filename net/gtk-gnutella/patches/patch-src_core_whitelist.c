$NetBSD: patch-src_core_whitelist.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/whitelist.c.orig	2022-02-25 16:06:20.000000000 +0000
+++ src/core/whitelist.c
@@ -339,7 +339,7 @@ whitelist_retrieve(void)
 		return;
 	}
 
-    while (fgets(ARYLEN(line), f)) {
+    while (fgets(line, sizeof(line), f)) {
 		pslist_t *sl_addr, *sl;
 		const char *endptr, *start;
 		host_addr_t addr;
