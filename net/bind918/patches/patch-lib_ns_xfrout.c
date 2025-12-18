$NetBSD: patch-lib_ns_xfrout.c,v 1.2 2025/12/18 10:35:13 he Exp $

* Based on NetBSD, add support for blocklist(blacklist).

--- lib/ns/xfrout.c.orig	2020-12-07 08:16:53.000000000 +0000
+++ lib/ns/xfrout.c
@@ -47,6 +47,10 @@
 #include <ns/stats.h>
 #include <ns/xfrout.h>
 
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+#include <ns/pfilter.h>
+#endif
+
 /*! \file
  * \brief
  * Outgoing AXFR and IXFR.
@@ -822,9 +826,15 @@ ns_xfr_start(ns_client_t *client, dns_rd
 					      ISC_LOG_ERROR,
 					      "zone transfer '%s/%s' denied",
 					      _buf1, _buf2);
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+				pfilter_notify(result, client, "zonexfr");
+#endif
 				goto cleanup;
 			}
 			if (result != ISC_R_SUCCESS) {
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+				pfilter_notify(result, client, "zonexfr");
+#endif
 				FAILQ(DNS_R_NOTAUTH, "non-authoritative zone",
 				      question_name, question_class);
 			}
