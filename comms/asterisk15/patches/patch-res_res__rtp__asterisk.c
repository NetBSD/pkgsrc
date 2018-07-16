$NetBSD: patch-res_res__rtp__asterisk.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_rtp_asterisk.c.orig	2018-06-20 15:19:48.478113854 +0000
+++ res/res_rtp_asterisk.c
@@ -46,13 +46,6 @@
 #include <openssl/bio.h>
 #endif
 
-#ifdef HAVE_PJPROJECT
-#include <pjlib.h>
-#include <pjlib-util.h>
-#include <pjnath.h>
-#include <ifaddrs.h>
-#endif
-
 #include "asterisk/options.h"
 #include "asterisk/stun.h"
 #include "asterisk/pbx.h"
@@ -72,7 +65,16 @@
 #include "asterisk/uuid.h"
 #include "asterisk/test.h"
 #include "asterisk/data_buffer.h"
+
+static int is_zero_address(struct in_addr *addr) {
+  return !addr->s_addr;
+}
 #ifdef HAVE_PJPROJECT
+#include <pjlib.h>
+#include <pjlib-util.h>
+#include <pjnath.h>
+#include <ifaddrs.h>
+
 #include "asterisk/res_pjproject.h"
 #endif
 
@@ -3254,7 +3256,7 @@ static void rtp_add_candidates_to_ice(st
 	}
 
 	/* If configured to use a STUN server to get our external mapped address do so */
-	if (count && stunaddr.sin_addr.s_addr && !stun_address_is_blacklisted(addr) &&
+	if (count && !is_zero_address(&stunaddr.sin_addr) && !stun_address_is_blacklisted(addr) &&
 		(ast_sockaddr_is_ipv4(addr) || ast_sockaddr_is_any(addr))) {
 		struct sockaddr_in answer;
 		int rsp;
