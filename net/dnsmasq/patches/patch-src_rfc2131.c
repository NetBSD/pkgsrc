$NetBSD: patch-src_rfc2131.c,v 1.1 2013/07/21 07:59:26 roy Exp $

Don't assume a trailing terminator.

--- src/rfc2131.c.orig	2013-04-17 12:52:49.000000000 +0000
+++ src/rfc2131.c
@@ -534,7 +534,7 @@ size_t dhcp_reply(struct dhcp_context *c
 	}
       
       if (fqdn_flags & 0x04)
-	while (*op != 0 && ((op + (*op) + 1) - pp) < len)
+	while (*op != 0 && ((op + (*op)) - pp) < len)
 	  {
 	    memcpy(pq, op+1, *op);
 	    pq += *op;
