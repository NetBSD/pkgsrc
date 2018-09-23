$NetBSD: patch-lib_dns_zone.c,v 1.1 2018/09/23 14:27:07 taca Exp $

* Backport change between BIND 9.11.4-P1 and 9.11.4-P2.

--- lib/dns/zone.c.orig	2018-07-24 17:26:47.000000000 +0000
+++ lib/dns/zone.c
@@ -1725,6 +1725,10 @@ dns_zone_isdynamic(dns_zone_t *zone, isc
 	    (zone->type == dns_zone_redirect && zone->masters != NULL))
 		return (ISC_TRUE);
 
+	/* Inline zones are always dynamic. */
+	if (zone->type == dns_zone_master && zone->raw != NULL)
+		return (ISC_TRUE);
+
 	/* If !ignore_freeze, we need check whether updates are disabled.  */
 	if (zone->type == dns_zone_master &&
 	    (!zone->update_disabled || ignore_freeze) &&
@@ -1737,6 +1741,11 @@ dns_zone_isdynamic(dns_zone_t *zone, isc
 }
 
 /*
+ * Note: when dealing with inline-signed zones, external callers will always
+ * call zone_load() for the secure zone; zone_load() calls itself recursively
+ * in order to load the raw zone.
+ */
+/*
  * Set the response policy index and information for a zone.
  */
 isc_result_t
@@ -1830,6 +1839,28 @@ zone_load(dns_zone_t *zone, unsigned int
 	INSIST(zone != zone->raw);
 	hasraw = inline_secure(zone);
 	if (hasraw) {
+		/*
+		 * We are trying to load an inline-signed zone.  First call
+		 * self recursively to try loading the raw version of the zone.
+		 * Assuming the raw zone file is readable, there are two
+		 * possibilities:
+		 *
+		 *  a) the raw zone was not yet loaded and thus it will be
+		 *     loaded now, synchronously; if this succeeds, a
+		 *     subsequent attempt to load the signed zone file will
+		 *     take place and thus zone_postload() will be called
+		 *     twice: first for the raw zone and then for the secure
+		 *     zone; the latter call will take care of syncing the raw
+		 *     version with the secure version,
+		 *
+		 *  b) the raw zone was already loaded and we are trying to
+		 *     reload it, which will happen asynchronously; this means
+		 *     zone_postload() will only be called for the raw zone
+		 *     because "result" returned by the zone_load() call below
+		 *     will not be ISC_R_SUCCESS but rather DNS_R_CONTINUE;
+		 *     zone_postload() called for the raw zone will take care
+		 *     of syncing the raw version with the secure version.
+		 */
 		result = zone_load(zone->raw, flags, ISC_FALSE);
 		if (result != ISC_R_SUCCESS) {
 			if (!locked)
@@ -1869,7 +1900,7 @@ zone_load(dns_zone_t *zone, unsigned int
 		 * zone being reloaded.  Do nothing - the database
 		 * we already have is guaranteed to be up-to-date.
 		 */
-		if (zone->type == dns_zone_master)
+		if (zone->type == dns_zone_master && !hasraw)
 			result = DNS_R_DYNAMIC;
 		else
 			result = ISC_R_SUCCESS;
@@ -1912,7 +1943,6 @@ zone_load(dns_zone_t *zone, unsigned int
 			goto cleanup;
 		}
 
-
 		/*
 		 * If the file modification time is in the past
 		 * set loadtime to that value.
@@ -4401,11 +4431,13 @@ zone_postload(dns_zone_t *zone, dns_db_t
 	    ! DNS_ZONE_OPTION(zone, DNS_ZONEOPT_NOMERGE) &&
 	    ! DNS_ZONE_FLAG(zone, DNS_ZONEFLG_LOADED))
 	{
-		if (zone->type == dns_zone_master &&
-		    (zone->update_acl != NULL || zone->ssutable != NULL))
+		if (zone->type == dns_zone_master && (inline_secure(zone) ||
+		    (zone->update_acl != NULL || zone->ssutable != NULL)))
+		{
 			options = DNS_JOURNALOPT_RESIGN;
-		else
+		} else {
 			options = 0;
+		}
 		result = dns_journal_rollforward(zone->mctx, db, options,
 						 zone->journal);
 		if (result != ISC_R_SUCCESS && result != ISC_R_NOTFOUND &&
@@ -4547,14 +4579,14 @@ zone_postload(dns_zone_t *zone, dns_db_t
 			    !isc_serial_gt(serial, oldserial)) {
 				isc_uint32_t serialmin, serialmax;
 
-				INSIST(zone->type == dns_zone_master);
+				INSIST(zone->raw == NULL);
 
 				if (serial == oldserial &&
 				    zone_unchanged(zone->db, db, zone->mctx)) {
 					dns_zone_log(zone, ISC_LOG_INFO,
 						     "ixfr-from-differences: "
 						     "unchanged");
-					return(ISC_R_SUCCESS);
+					goto done;
 				}
 
 				serialmin = (oldserial + 1) & 0xffffffffU;
@@ -4778,8 +4810,7 @@ zone_postload(dns_zone_t *zone, dns_db_t
 			     dns_db_issecure(db) ? " (DNSSEC signed)" : "");
 
 	zone->loadtime = loadtime;
-	DNS_ZONE_CLRFLAG(zone, DNS_ZONEFLG_LOADPENDING);
-	return (result);
+	goto done;
 
  cleanup:
 	for (inc = ISC_LIST_HEAD(zone->newincludes);
@@ -4816,6 +4847,23 @@ zone_postload(dns_zone_t *zone, dns_db_t
 			result = ISC_R_SUCCESS;
 	}
 
+ done:
+	DNS_ZONE_CLRFLAG(zone, DNS_ZONEFLG_LOADPENDING);
+	/*
+	 * If this is an inline-signed zone and we were called for the raw
+	 * zone, we need to clear DNS_ZONEFLG_LOADPENDING for the secure zone
+	 * as well, but only if this is a reload, not an initial zone load: in
+	 * the former case, zone_postload() will not be run for the secure
+	 * zone; in the latter case, it will be.  Check which case we are
+	 * dealing with by consulting the DNS_ZONEFLG_LOADED flag for the
+	 * secure zone: if it is set, this must be a reload.
+	 */
+	if (inline_raw(zone) &&
+	    DNS_ZONE_FLAG(zone->secure, DNS_ZONEFLG_LOADED))
+	{
+		DNS_ZONE_CLRFLAG(zone->secure, DNS_ZONEFLG_LOADPENDING);
+	}
+
 	return (result);
 }
 
