$NetBSD: patch-bin_named_zoneconf.c,v 1.1 2018/09/23 14:27:07 taca Exp $

* Backport change between BIND 9.11.4-P1 and 9.11.4-P2.

--- bin/named/zoneconf.c.orig	2018-07-24 17:26:47.000000000 +0000
+++ bin/named/zoneconf.c
@@ -1214,7 +1214,7 @@ ns_zone_configure(const cfg_obj_t *confi
 			dns_zone_setoption(raw, DNS_ZONEOPT_IXFRFROMDIFFS,
 					   ISC_TRUE);
 			dns_zone_setoption(zone, DNS_ZONEOPT_IXFRFROMDIFFS,
-					   ISC_TRUE);
+					   ISC_FALSE);
 		} else
 			dns_zone_setoption(zone, DNS_ZONEOPT_IXFRFROMDIFFS,
 					   ixfrdiff);
