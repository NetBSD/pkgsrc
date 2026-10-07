$NetBSD: patch-lib_tsocket_tsocket__bsd.c,v 1.4 2026/10/07 08:53:53 wiz Exp $

Avoid s_addr macro.

--- lib/tsocket/tsocket_bsd.c.orig	2026-08-10 19:16:53.014630000 +0000
+++ lib/tsocket/tsocket_bsd.c
@@ -441,7 +441,7 @@ int _tsocket_address_inet_from_hostport_strings(TALLOC
 	char *buf = NULL;
 	uint64_t port = 0;
 	int ret;
-	char *s_addr = NULL;
+	char *sun_addr = NULL;
 	uint16_t s_port = default_port;
 	int error = 0;
 	bool is_ipv6_by_squares = false;
@@ -470,7 +470,7 @@ int _tsocket_address_inet_from_hostport_strings(TALLOC
 		/* IPv6 possibly with port - squares detected */
 		port_sep = pr_sq + 1;
 		if (*port_sep == '\0') {
-			s_addr = pl_sq + 1;
+			sun_addr = pl_sq + 1;
 			*pr_sq = 0;
 			s_port = default_port;
 			goto get_addr;
@@ -493,7 +493,7 @@ int _tsocket_address_inet_from_hostport_strings(TALLOC
 		s_port = (uint16_t)port;
 		*port_sep = 0;
 		*pr_sq = 0;
-		s_addr = pl_sq + 1;
+		sun_addr = pl_sq + 1;
 		*pl_sq = 0;
 		goto get_addr;
 	} else if (pl_period != NULL && port_sep != NULL) {
@@ -511,18 +511,18 @@ int _tsocket_address_inet_from_hostport_strings(TALLOC
 		}
 		s_port = (uint16_t)port;
 		*port_sep = 0;
-		s_addr = buf;
+		sun_addr = buf;
 		goto get_addr;
 	} else {
 		/* Everything else, let tsocket_address_inet_from string() */
 		/* find parsing errors */
-		s_addr = buf;
+		sun_addr = buf;
 		s_port = default_port;
 		goto get_addr;
 	}
 get_addr:
 	ret = _tsocket_address_inet_from_strings(
-	    mem_ctx, fam, s_addr, s_port, _addr, location);
+	    mem_ctx, fam, sun_addr, s_port, _addr, location);
 
 	return ret;
 }
