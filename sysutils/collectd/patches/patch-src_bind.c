$NetBSD: patch-src_bind.c,v 1.2 2020/10/24 22:39:45 wiz Exp $

Also pick out the response time bins from the resolver stats.

--- src/bind.c.orig	2020-03-08 16:57:09.000000000 +0100
+++ src/bind.c	2020-07-20 12:55:28.000000000 +0200
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
