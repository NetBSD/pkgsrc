$NetBSD: patch-lib_ns_xfrout.c,v 1.2 2020/12/19 16:41:36 taca Exp $

* Based on NetBSD, add support for blocklist(blacklist).

--- lib/ns/xfrout.c.orig	2020-12-07 08:16:53.000000000 +0000
+++ lib/ns/xfrout.c
@@ -44,6 +44,10 @@
 #include <ns/stats.h>
 #include <ns/xfrout.h>
 
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+#include <ns/pfilter.h>
+#endif
+
 /*! \file
  * \brief
  * Outgoing AXFR and IXFR.
@@ -818,9 +822,15 @@ ns_xfr_start(ns_client_t *client, dns_rd
 					      ISC_LOG_ERROR,
 					      "zone transfer '%s/%s' denied",
 					      _buf1, _buf2);
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+				pfilter_notify(result, client, "zonexfr");
+#endif
 				goto failure;
 			}
 			if (result != ISC_R_SUCCESS) {
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+				pfilter_notify(result, client, "zonexfr");
+#endif
 				FAILQ(DNS_R_NOTAUTH, "non-authoritative zone",
 				      question_name, question_class);
 			}
