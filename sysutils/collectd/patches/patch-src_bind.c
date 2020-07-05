$NetBSD: patch-src_bind.c,v 1.1 2020/07/05 13:57:32 he Exp $

Also pick out the response time bins from the resolver stats.

--- src/bind.c.orig	2017-11-18 09:03:27.000000000 +0000
+++ src/bind.c
@@ -228,7 +228,17 @@ static const translation_info_t resstats
         {"ValAttempt", "dns_resolver", "DNSSEC-attempt"},
         {"ValOk", "dns_resolver", "DNSSEC-okay"},
         {"ValNegOk", "dns_resolver", "DNSSEC-negokay"},
-        {"ValFail", "dns_resolver", "DNSSEC-fail"}};
+        {"ValFail", "dns_resolver", "DNSSEC-fail"},
+
+	/* Query RTT information */
+	{"QryRTT10", "dns_resolver", "rtt10"},
+	{"QryRTT100", "dns_resolver", "rtt100"},
+	{"QryRTT500", "dns_resolver", "rtt500"},
+	{"QryRTT800", "dns_resolver", "rtt800"},
+	{"QryRTT1600", "dns_resolver", "rtt1600"},
+	{"QryRTT1600+", "dns_resolver", "rtt1600plus"}
+};
+
 static int resstats_translation_table_length =
     STATIC_ARRAY_SIZE(resstats_translation_table);
 /* }}} */
