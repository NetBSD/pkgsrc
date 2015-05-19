$NetBSD: patch-src_racoon_gssapi.c,v 1.1 2015/05/19 15:45:44 sevan Exp $

Protect against a NULL pointer dereference described in:
https://www.altsci.com/ipsec/

--- src/racoon/gssapi.c.orig	2015-05-19 15:28:49.000000000 +0000
+++ src/racoon/gssapi.c
@@ -192,6 +192,11 @@ gssapi_init(struct ph1handle *iph1)
 	gss_name_t princ, canon_princ;
 	OM_uint32 maj_stat, min_stat;
 
+	if (iph1->rmconf == NULL) {
+		plog(LLV_ERROR, LOCATION, NULL, "no remote config\n");
+		return -1;
+	}
+
 	gps = racoon_calloc(1, sizeof (struct gssapi_ph1_state));
 	if (gps == NULL) {
 		plog(LLV_ERROR, LOCATION, NULL, "racoon_calloc failed\n");
