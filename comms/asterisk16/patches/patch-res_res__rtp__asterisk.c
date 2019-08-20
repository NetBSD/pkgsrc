$NetBSD: patch-res_res__rtp__asterisk.c,v 1.1 2019/08/20 13:47:42 ryoon Exp $

--- res/res_rtp_asterisk.c.orig	2019-07-25 09:38:14.000000000 +0000
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
@@ -3393,7 +3397,7 @@ static void rtp_add_candidates_to_ice(st
 	}
 
 	/* If configured to use a STUN server to get our external mapped address do so */
-	if (count && stunaddr.sin_addr.s_addr && !stun_address_is_blacklisted(addr) &&
+	if (count && !is_zero_address(&stunaddr.sin_addr) && !stun_address_is_blacklisted(addr) &&
 		(ast_sockaddr_is_ipv4(addr) || ast_sockaddr_is_any(addr))) {
 		struct sockaddr_in answer;
 		int rsp;
