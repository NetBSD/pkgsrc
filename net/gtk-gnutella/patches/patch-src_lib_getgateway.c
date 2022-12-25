$NetBSD: patch-src_lib_getgateway.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/lib/getgateway.c.orig	2022-02-25 16:06:21.000000000 +0000
+++ src/lib/getgateway.c
@@ -101,7 +101,7 @@ parse_netstat(host_addr_t *addrp)
 	 * output is "default" for the default route.
 	 */
 
-	while (fgets(ARYLEN(tmp), f)) {
+	while (fgets(tmp, sizeof(tmp), f)) {
 		char *p;
 		uint32 ip;
 
