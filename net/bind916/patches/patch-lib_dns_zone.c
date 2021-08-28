$NetBSD: patch-lib_dns_zone.c,v 1.2.4.1 2021/08/28 09:22:55 bsiegert Exp $

No need to use atomic 64-bit integers for flags fit within 32-bit width.

--- lib/dns/zone.c.orig	2021-06-18 19:08:07.000000000 +0900
+++ lib/dns/zone.c	2021-07-19 08:46:21.613595923 +0900
@@ -241,8 +241,13 @@ struct dns_zone {
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
@@ -387,7 +392,11 @@ struct dns_zone {
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
@@ -524,7 +533,9 @@ typedef enum {
 	 * support 64-bit enum values. Currently they fail on
 	 * Windows.
 	 */
+#if 0
 	DNS_ZONEFLG___MAX = UINT64_MAX, /* trick to make the ENUM 64-bit wide */
+#endif
 } dns_zoneflg_t;
 
 #define DNS_ZONE_OPTION(z, o)	 ((atomic_load_relaxed(&(z)->options) & (o)) != 0)
