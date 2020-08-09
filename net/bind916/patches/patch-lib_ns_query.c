$NetBSD: patch-lib_ns_query.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/ns/query.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/ns/query.c
@@ -68,6 +68,10 @@
 #include <ns/stats.h>
 #include <ns/xfrout.h>
 
+#ifdef HAVE_BLACKLIST
+#include <ns/pfilter.h>
+#endif
+
 #if 0
 /*
  * It has been recommended that DNS64 be changed to return excluded
@@ -857,6 +861,9 @@ query_checkcacheaccess(ns_client_t *clie
 					      msg);
 			}
 		} else if (log) {
+#ifdef HAVE_BLACKLIST
+			pfilter_notify(result, client, "checkcacheaccess");
+#endif
 			/*
 			 * We were denied by the "allow-query-cache" ACL.
 			 * There is no need to clear NS_QUERYATTR_CACHEACLOK
@@ -989,6 +996,9 @@ query_validatezonedb(ns_client_t *client
 					      msg);
 			}
 		} else {
+#ifdef HAVE_BLACKLIST
+			pfilter_notify(result, client, "validatezonedb");
+#endif
 			ns_client_aclmsg("query", name, qtype,
 					 client->view->rdclass, msg,
 					 sizeof(msg));
