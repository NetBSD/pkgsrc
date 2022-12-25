$NetBSD: patch-src_lib_getgateway.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/lib/getgateway.c.orig	2022-02-25 16:06:21.000000000 +0000
+++ src/lib/getgateway.c
@@ -101,7 +101,7 @@ parse_netstat(host_addr_t *addrp)
 	 * output is "default" for the default route.
 	 */
 
-	while (fgets(ARYLEN(tmp), f)) {
+	while (fgets(tmp, sizeof(tmp), f)) {
 		char *p;
 		uint32 ip;
 
