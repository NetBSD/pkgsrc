$NetBSD: patch-bin_named_server.c,v 1.1 2018/09/23 14:27:07 taca Exp $

* Backport change between BIND 9.11.4-P1 and 9.11.4-P2.

--- bin/named/server.c.orig	2018-07-24 17:26:47.000000000 +0000
+++ bin/named/server.c
@@ -9345,7 +9345,7 @@ ns_server_freeze(ns_server_t *server, is
 		 isc_lex_t *lex, isc_buffer_t *text)
 {
 	isc_result_t result, tresult;
-	dns_zone_t *zone = NULL, *raw = NULL;
+	dns_zone_t *mayberaw = NULL, *raw = NULL;
 	dns_zonetype_t type;
 	char classstr[DNS_RDATACLASS_FORMATSIZE];
 	char zonename[DNS_NAME_FORMATSIZE];
@@ -9354,11 +9354,11 @@ ns_server_freeze(ns_server_t *server, is
 	isc_boolean_t frozen;
 	const char *msg = NULL;
 
-	result = zone_from_args(server, lex, NULL, &zone, NULL,
+	result = zone_from_args(server, lex, NULL, &mayberaw, NULL,
 				text, ISC_TRUE);
 	if (result != ISC_R_SUCCESS)
 		return (result);
-	if (zone == NULL) {
+	if (mayberaw == NULL) {
 		result = isc_task_beginexclusive(server->task);
 		RUNTIME_CHECK(result == ISC_R_SUCCESS);
 		tresult = ISC_R_SUCCESS;
@@ -9378,26 +9378,26 @@ ns_server_freeze(ns_server_t *server, is
 			      isc_result_totext(tresult));
 		return (tresult);
 	}
-	dns_zone_getraw(zone, &raw);
+	dns_zone_getraw(mayberaw, &raw);
 	if (raw != NULL) {
-		dns_zone_detach(&zone);
-		dns_zone_attach(raw, &zone);
+		dns_zone_detach(&mayberaw);
+		dns_zone_attach(raw, &mayberaw);
 		dns_zone_detach(&raw);
 	}
-	type = dns_zone_gettype(zone);
+	type = dns_zone_gettype(mayberaw);
 	if (type != dns_zone_master) {
-		dns_zone_detach(&zone);
+		dns_zone_detach(&mayberaw);
 		return (DNS_R_NOTMASTER);
 	}
 
-	if (freeze && !dns_zone_isdynamic(zone, ISC_TRUE)) {
-		dns_zone_detach(&zone);
+	if (freeze && !dns_zone_isdynamic(mayberaw, ISC_TRUE)) {
+		dns_zone_detach(&mayberaw);
 		return (DNS_R_NOTDYNAMIC);
 	}
 
 	result = isc_task_beginexclusive(server->task);
 	RUNTIME_CHECK(result == ISC_R_SUCCESS);
-	frozen = dns_zone_getupdatedisabled(zone);
+	frozen = dns_zone_getupdatedisabled(mayberaw);
 	if (freeze) {
 		if (frozen) {
 			msg = "WARNING: The zone was already frozen.\n"
@@ -9406,16 +9406,16 @@ ns_server_freeze(ns_server_t *server, is
 			result = DNS_R_FROZEN;
 		}
 		if (result == ISC_R_SUCCESS) {
-			result = dns_zone_flush(zone);
+			result = dns_zone_flush(mayberaw);
 			if (result != ISC_R_SUCCESS)
 				msg = "Flushing the zone updates to "
 				      "disk failed.";
 		}
 		if (result == ISC_R_SUCCESS)
-			dns_zone_setupdatedisabled(zone, freeze);
+			dns_zone_setupdatedisabled(mayberaw, freeze);
 	} else {
 		if (frozen) {
-			result = dns_zone_loadandthaw(zone);
+			result = dns_zone_loadandthaw(mayberaw);
 			switch (result) {
 			case ISC_R_SUCCESS:
 			case DNS_R_UPTODATE:
@@ -9437,7 +9437,7 @@ ns_server_freeze(ns_server_t *server, is
 		isc_buffer_putmem(text, (const unsigned char *)msg,
 				  strlen(msg) + 1);
 
-	view = dns_zone_getview(zone);
+	view = dns_zone_getview(mayberaw);
 	if (strcmp(view->name, "_default") == 0 ||
 	    strcmp(view->name, "_bind") == 0)
 	{
@@ -9447,9 +9447,9 @@ ns_server_freeze(ns_server_t *server, is
 		vname = view->name;
 		sep = " ";
 	}
-	dns_rdataclass_format(dns_zone_getclass(zone), classstr,
+	dns_rdataclass_format(dns_zone_getclass(mayberaw), classstr,
 			      sizeof(classstr));
-	dns_name_format(dns_zone_getorigin(zone),
+	dns_name_format(dns_zone_getorigin(mayberaw),
 			zonename, sizeof(zonename));
 	isc_log_write(ns_g_lctx, NS_LOGCATEGORY_GENERAL,
 		      NS_LOGMODULE_SERVER, ISC_LOG_INFO,
@@ -9457,7 +9457,7 @@ ns_server_freeze(ns_server_t *server, is
 		      freeze ? "freezing" : "thawing",
 		      zonename, classstr, sep, vname,
 		      isc_result_totext(result));
-	dns_zone_detach(&zone);
+	dns_zone_detach(&mayberaw);
 	return (result);
 }
 
