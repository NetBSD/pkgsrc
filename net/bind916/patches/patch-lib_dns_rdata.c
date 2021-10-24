$NetBSD: patch-lib_dns_rdata.c,v 1.1 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- lib/dns/rdata.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/dns/rdata.c
@@ -1888,8 +1888,8 @@ inet_totext(int af, uint32_t flags, isc_
 	 * parsing, so append 0 in that case.
 	 */
 	if (af == AF_INET6 && (flags & DNS_STYLEFLAG_YAML) != 0) {
-		isc_textregion_t tr;
-		isc_buffer_usedregion(target, (isc_region_t *)&tr);
+		isc_region_t tr;
+		isc_buffer_usedregion(target, &tr);
 		if (tr.base[tr.length - 1] == ':') {
 			if (isc_buffer_availablelength(target) == 0) {
 				return (ISC_R_NOSPACE);
