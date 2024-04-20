$NetBSD: patch-lib_ns_query.c,v 1.2 2024/04/20 14:02:40 taca Exp $

* Based on NetBSD, add support for blocklist(blacklist).

--- lib/ns/query.c.orig	2024-04-03 09:39:01.839989165 +0000
+++ lib/ns/query.c
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
@@ -1047,6 +1051,9 @@ query_validatezonedb(ns_client_t *client
 					      msg);
 			}
 		} else {
+#if defined(HAVE_BLACKLIST_H) || defined(HAVE_BLOCKLIST_H)
+			pfilter_notify(result, client, "validatezonedb");
+#endif
 			ns_client_aclmsg("query", name, qtype,
 					 client->view->rdclass, msg,
 					 sizeof(msg));
