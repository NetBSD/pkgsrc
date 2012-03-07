$NetBSD: patch-lib_dns_zone.c,v 1.1.1.1 2012/03/07 14:25:00 taca Exp $

* Avoid to use bool as variable name.

--- lib/dns/zone.c.orig	2012-02-23 07:09:02.000000000 +0000
+++ lib/dns/zone.c
@@ -15780,9 +15780,9 @@ dns_zone_setrefreshkeyinterval(dns_zone_
 }
 
 void
-dns_zone_setrequestixfr(dns_zone_t *zone, isc_boolean_t bool) {
+dns_zone_setrequestixfr(dns_zone_t *zone, isc_boolean_t isc_bool) {
 	REQUIRE(DNS_ZONE_VALID(zone));
-	zone->requestixfr = bool;
+	zone->requestixfr = isc_bool;
 }
 
 isc_boolean_t
