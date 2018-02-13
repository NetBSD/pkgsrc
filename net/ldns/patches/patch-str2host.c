$NetBSD: patch-str2host.c,v 1.1 2018/02/13 15:08:11 he Exp $

Apply fix for CVE-2017-1000232 from
https://git.nlnetlabs.nl/ldns/commit/?id=3bdeed02

--- str2host.c.orig	2014-01-10 21:04:41.000000000 +0000
+++ str2host.c
@@ -1458,7 +1458,10 @@ ldns_str2rdf_long_str(ldns_rdf **rd, con
 	if (! str) {
 		return LDNS_STATUS_SYNTAX_BAD_ESCAPE;
 	}
-	length = (size_t)(dp - data);
+	if (!(length = (size_t)(dp - data))) {
+		LDNS_FREE(data);
+		return LDNS_STATUS_SYNTAX_EMPTY;
+	}
 
 	/* Lose the overmeasure */
 	data = LDNS_XREALLOC(dp = data, uint8_t, length);
