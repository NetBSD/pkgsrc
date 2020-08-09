$NetBSD: patch-lib_ns_xfrout.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/ns/xfrout.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/ns/xfrout.c
@@ -46,6 +46,10 @@
 #include <ns/stats.h>
 #include <ns/xfrout.h>
 
+#ifdef HAVE_BLACKLIST
+#include <ns/pfilter.h>
+#endif
+
 /*! \file
  * \brief
  * Outgoing AXFR and IXFR.
@@ -821,9 +825,15 @@ ns_xfr_start(ns_client_t *client, dns_rd
 					      ISC_LOG_ERROR,
 					      "zone transfer '%s/%s' denied",
 					      _buf1, _buf2);
+#ifdef HAVE_BLACKLIST
+				pfilter_notify(result, client, "zonexfr");
+#endif
 				goto failure;
 			}
 			if (result != ISC_R_SUCCESS) {
+#ifdef HAVE_BLACKLIST
+				pfilter_notify(result, client, "zonexfr");
+#endif
 				FAILQ(DNS_R_NOTAUTH, "non-authoritative zone",
 				      question_name, question_class);
 			}
