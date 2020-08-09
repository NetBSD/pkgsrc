$NetBSD: patch-lib_isc_netmgr_tcp.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/netmgr/tcp.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/netmgr/tcp.c
@@ -36,7 +36,7 @@
 static atomic_uint_fast32_t last_tcpquota_log = ATOMIC_VAR_INIT(0);
 
 static bool
-can_log_tcp_quota() {
+can_log_tcp_quota(void) {
 	isc_stdtime_t now, last;
 
 	isc_stdtime_get(&now);
