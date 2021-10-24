$NetBSD: patch-lib_dns_include_dns_zone.h,v 1.3 2021/10/24 06:40:28 taca Exp $

No need to use atomic 64-bit integers for flags fit within 32-bit width.

--- lib/dns/include/dns/zone.h.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/dns/include/dns/zone.h
@@ -96,7 +96,9 @@ typedef enum {
 	DNS_ZONEOPT_CHECKSPF = 1 << 27,		/*%< check SPF records */
 	DNS_ZONEOPT_CHECKTTL = 1 << 28,		/*%< check max-zone-ttl */
 	DNS_ZONEOPT_AUTOEMPTY = 1 << 29,	/*%< automatic empty zone */
+#if 0
 	DNS_ZONEOPT___MAX = UINT64_MAX, /* trick to make the ENUM 64-bit wide */
+#endif
 } dns_zoneopt_t;
 
 /*
@@ -108,7 +110,9 @@ typedef enum {
 	DNS_ZONEKEY_CREATE = 0x00000004U,   /*%< make keys when needed */
 	DNS_ZONEKEY_FULLSIGN = 0x00000008U, /*%< roll to new keys immediately */
 	DNS_ZONEKEY_NORESIGN = 0x00000010U, /*%< no automatic resigning */
+#if 0
 	DNS_ZONEKEY___MAX = UINT64_MAX, /* trick to make the ENUM 64-bit wide */
+#endif
 } dns_zonekey_t;
 
 #ifndef DNS_ZONE_MINREFRESH
