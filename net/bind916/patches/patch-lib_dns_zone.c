$NetBSD: patch-lib_dns_zone.c,v 1.2 2021/03/21 04:16:17 taca Exp $

* Take from NetBSD base.

--- lib/dns/zone.c.orig	2021-03-11 13:20:59.000000000 +0000
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
