$NetBSD: patch-lib_dns_zone.c,v 1.5 2021/10/24 06:40:28 taca Exp $

No need to use atomic 64-bit integers for flags fit within 32-bit width.

--- lib/dns/zone.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/dns/zone.c
@@ -246,8 +246,13 @@ struct dns_zone {
 	int32_t journalsize;
 	dns_rdataclass_t rdclass;
 	dns_zonetype_t type;
+#if 1
+	atomic_uint_fast32_t flags;
+	atomic_uint_fast32_t options;
+#else
 	atomic_uint_fast64_t flags;
 	atomic_uint_fast64_t options;
+#endif
 	unsigned int db_argc;
 	char **db_argv;
 	isc_time_t expiretime;
@@ -405,7 +410,11 @@ struct dns_zone {
 	/*%
 	 * Autosigning/key-maintenance options
 	 */
+#if 1
+	atomic_uint_fast32_t keyopts;
+#else
 	atomic_uint_fast64_t keyopts;
+#endif
 
 	/*%
 	 * True if added by "rndc addzone"
@@ -537,12 +546,14 @@ typedef enum {
 						      * notify due to the zone
 						      * just being loaded for
 						      * the first time. */
+#if 0
 	/*
 	 * DO NOT add any new zone flags here until all platforms
 	 * support 64-bit enum values. Currently they fail on
 	 * Windows.
 	 */
 	DNS_ZONEFLG___MAX = UINT64_MAX, /* trick to make the ENUM 64-bit wide */
+#endif
 } dns_zoneflg_t;
 
 #define DNS_ZONE_OPTION(z, o)	 ((atomic_load_relaxed(&(z)->options) & (o)) != 0)
