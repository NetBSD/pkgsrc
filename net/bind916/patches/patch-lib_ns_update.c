$NetBSD: patch-lib_ns_update.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/ns/update.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/ns/update.c
@@ -52,6 +52,10 @@
 #include <ns/stats.h>
 #include <ns/update.h>
 
+#ifdef HAVE_BLACKLIST
+#include <ns/pfilter.h>
+#endif
+
 /*! \file
  * \brief
  * This module implements dynamic update as in RFC2136.
@@ -340,6 +344,9 @@ checkqueryacl(ns_client_t *client, dns_a
 
 	result = ns_client_checkaclsilent(client, NULL, queryacl, true);
 	if (result != ISC_R_SUCCESS) {
+#ifdef HAVE_BLACKLIST
+		pfilter_notify(result, client, "queryacl");
+#endif
 		dns_name_format(zonename, namebuf, sizeof(namebuf));
 		dns_rdataclass_format(client->view->rdclass, classbuf,
 				      sizeof(classbuf));
@@ -352,6 +359,9 @@ checkqueryacl(ns_client_t *client, dns_a
 			      "update '%s/%s' denied due to allow-query",
 			      namebuf, classbuf);
 	} else if (updateacl == NULL && ssutable == NULL) {
+#ifdef HAVE_BLACKLIST
+		pfilter_notify(result, client, "updateacl");
+#endif
 		dns_name_format(zonename, namebuf, sizeof(namebuf));
 		dns_rdataclass_format(client->view->rdclass, classbuf,
 				      sizeof(classbuf));
@@ -393,6 +403,9 @@ checkupdateacl(ns_client_t *client, dns_
 		msg = "disabled";
 	} else {
 		result = ns_client_checkaclsilent(client, NULL, acl, false);
+#ifdef HAVE_BLACKLIST
+		pfilter_notify(result, client, "updateacl");
+#endif
 		if (result == ISC_R_SUCCESS) {
 			level = ISC_LOG_DEBUG(3);
 			msg = "approved";
