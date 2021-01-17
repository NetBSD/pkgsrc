$NetBSD: patch-res_res__rtp__asterisk.c,v 1.2 2021/01/17 08:32:40 jnemeth Exp $

--- res/res_rtp_asterisk.c.orig	2019-09-05 13:09:20.000000000 +0000
+++ res/res_rtp_asterisk.c
@@ -56,13 +56,6 @@
 #endif
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
@@ -82,7 +75,16 @@
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
 
@@ -3297,7 +3299,7 @@ static void rtp_add_candidates_to_ice(st
 	}
 
 	/* If configured to use a STUN server to get our external mapped address do so */
-	if (count && stunaddr.sin_addr.s_addr && !stun_address_is_blacklisted(addr) &&
+	if (count && !is_zero_address(&stunaddr.sin_addr) && !stun_address_is_blacklisted(addr) &&
 		(ast_sockaddr_is_ipv4(addr) || ast_sockaddr_is_any(addr))) {
 		struct sockaddr_in answer;
 		int rsp;
