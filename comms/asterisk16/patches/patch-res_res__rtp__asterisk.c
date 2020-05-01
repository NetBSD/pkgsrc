$NetBSD: patch-res_res__rtp__asterisk.c,v 1.2 2020/05/01 07:57:36 ryoon Exp $

--- res/res_rtp_asterisk.c.orig	2020-04-30 14:11:40.000000000 +0000
+++ res/res_rtp_asterisk.c
@@ -63,6 +63,10 @@
 #include <ifaddrs.h>
 #endif
 
+static int is_zero_address(struct in_addr *addr) {
+  return !addr->s_addr;
+}
+
 #include "asterisk/options.h"
 #include "asterisk/stun.h"
 #include "asterisk/pbx.h"
@@ -3581,7 +3585,7 @@ static void rtp_add_candidates_to_ice(st
 	}
 
 	/* If configured to use a STUN server to get our external mapped address do so */
-	if (stunaddr.sin_addr.s_addr && !stun_address_is_blacklisted(addr) &&
+	if (!is_zero_address(&stunaddr.sin_addr) && !stun_address_is_blacklisted(addr) &&
 		(ast_sockaddr_is_ipv4(addr) || ast_sockaddr_is_any(addr)) &&
 		count < PJ_ICE_MAX_CAND) {
 		struct sockaddr_in answer;
