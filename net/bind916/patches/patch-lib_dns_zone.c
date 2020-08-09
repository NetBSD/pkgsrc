$NetBSD: patch-lib_dns_zone.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/zone.c.orig	2020-06-10 21:01:43.000000000 +0000
+++ lib/dns/zone.c
@@ -224,8 +224,13 @@ struct dns_zone {
 	int32_t journalsize;
 	dns_rdataclass_t rdclass;
 	dns_zonetype_t type;
+#ifdef __NetBSD__
+	atomic_uint_fast32_t flags;
+	atomic_uint_fast32_t options;
+#else
 	atomic_uint_fast64_t flags;
 	atomic_uint_fast64_t options;
+#endif
 	unsigned int db_argc;
 	char **db_argv;
 	isc_time_t expiretime;
@@ -370,7 +375,11 @@ struct dns_zone {
 	/*%
 	 * Autosigning/key-maintenance options
 	 */
+#ifdef __NetBSD__
+	atomic_uint_fast32_t keyopts;
+#else
 	atomic_uint_fast64_t keyopts;
+#endif
 
 	/*%
 	 * True if added by "rndc addzone"
@@ -499,7 +508,9 @@ typedef enum {
 						      * notify due to the zone
 						      * just being loaded for
 						      * the first time.  */
+#ifndef __NetBSD__
 	DNS_ZONEFLG___MAX = UINT64_MAX, /* trick to make the ENUM 64-bit wide */
+#endif
 } dns_zoneflg_t;
 
 #define DNS_ZONE_OPTION(z, o)	 ((atomic_load_relaxed(&(z)->options) & (o)) != 0)
