$NetBSD: patch-lib_dns_message.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Avoid uninitialized variable warning.

--- lib/dns/message.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/message.c
@@ -996,7 +996,7 @@ getquestions(isc_buffer_t *source, dns_m
 	dns_name_t *name;
 	dns_name_t *name2;
 	dns_offsets_t *offsets;
-	dns_rdataset_t *rdataset;
+	dns_rdataset_t *rdataset = NULL;
 	dns_rdatalist_t *rdatalist;
 	isc_result_t result;
 	dns_rdatatype_t rdtype;
