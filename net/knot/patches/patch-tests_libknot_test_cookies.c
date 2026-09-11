$NetBSD: patch-tests_libknot_test_cookies.c,v 1.1 2026/09/11 12:53:14 drixter Exp $

Patch from upstream to work on SmartOS #980

--- tests/libknot/test_cookies.c.orig	2026-09-10 18:04:46.963249178 +0000
+++ tests/libknot/test_cookies.c
@@ -14,11 +14,11 @@
 #include "contrib/sockaddr.h"
 
 static knot_edns_cookie_t client_generate(
-	struct sockaddr_storage *s_addr, const uint8_t *c_secret,
+	struct sockaddr_storage *srv_addr, const uint8_t *c_secret,
 	const char *msg, int code, const char *ref)
 {
 	knot_edns_cookie_params_t params = {
-		.server_addr = s_addr,
+		.server_addr = srv_addr,
 	};
 	memcpy(params.secret, c_secret, sizeof(params.secret));
 
@@ -54,11 +54,11 @@ static knot_edns_cookie_t server_generat
 }
 
 static void client_check(
-	struct sockaddr_storage *s_addr, const uint8_t *secret,
+	struct sockaddr_storage *srv_addr, const uint8_t *secret,
 	knot_edns_cookie_t *cc, const char *msg, int code)
 {
 	knot_edns_cookie_params_t params = {
-		.server_addr = s_addr,
+		.server_addr = srv_addr,
 	};
 	memcpy(params.secret, secret, sizeof(params.secret));
 
