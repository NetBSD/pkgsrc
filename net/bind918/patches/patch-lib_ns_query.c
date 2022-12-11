$NetBSD: patch-lib_ns_query.c,v 1.1 2022/12/11 01:57:55 sekiya Exp $

* Based on NetBSD, add support for blocklist(blacklist).

--- lib/ns/query.c.orig	2022-11-08 07:17:42.056257919 +0900
+++ lib/ns/query.c	2022-12-10 11:00:47.549957781 +0900
@@ -74,6 +74,10 @@
 #include <ns/stats.h>
 #include <ns/xfrout.h>
 
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+#include <ns/pfilter.h>
+#endif
+
 #if 0
 /*
  * It has been recommended that DNS64 be changed to return excluded
@@ -915,6 +919,9 @@
 						NULL);
 
 			if (log) {
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+				pfilter_notify(result, client, "checkcacheaccess");
+#endif
 				ns_client_aclmsg("query (cache)", name, qtype,
 						 client->view->rdclass, msg,
 						 sizeof(msg));
@@ -1043,6 +1050,9 @@
 					      msg);
 			}
 		} else {
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+			pfilter_notify(result, client, "validatezonedb");
+#endif
 			ns_client_aclmsg("query", name, qtype,
 					 client->view->rdclass, msg,
 					 sizeof(msg));
