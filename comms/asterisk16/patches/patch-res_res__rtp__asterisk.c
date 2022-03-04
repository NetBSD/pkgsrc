$NetBSD: patch-res_res__rtp__asterisk.c,v 1.5 2022/03/04 12:22:31 ryoon Exp $

--- res/res_rtp_asterisk.c.orig	2022-02-10 11:53:37.000000000 +0000
+++ res/res_rtp_asterisk.c
@@ -69,6 +69,10 @@
 #include <ifaddrs.h>
 #endif
 
+static int is_zero_address(struct in_addr *addr) {
+  return !addr->s_addr;
+}
+
 #include "asterisk/conversions.h"
 #include "asterisk/options.h"
 #include "asterisk/logger_category.h"
@@ -3654,7 +3658,7 @@ static void rtp_add_candidates_to_ice(st
 	ast_rwlock_unlock(&stunaddr_lock);
 
 	/* If configured to use a STUN server to get our external mapped address do so */
-	if (stunaddr_copy.sin_addr.s_addr && !stun_address_is_blacklisted(addr) &&
+        if (!is_zero_address(&stunaddr.sin_addr) && !stun_address_is_blacklisted(addr) &&
 		(ast_sockaddr_is_ipv4(addr) || ast_sockaddr_is_any(addr)) &&
 		count < PJ_ICE_MAX_CAND) {
 		struct sockaddr_in answer;
