$NetBSD: patch-lib_ns_client.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/ns/client.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/ns/client.c
@@ -87,8 +87,8 @@
 	isc_log_write(ns_lctx, NS_LOGCATEGORY_CLIENT, NS_LOGMODULE_CLIENT, \
 		      ISC_LOG_DEBUG(3), "clientmgr @%p: %s", manager, (m))
 #else /* ifdef NS_CLIENT_TRACE */
-#define CTRACE(m) ((void)(m))
-#define MTRACE(m) ((void)(m))
+#define CTRACE(m) ((void)/*LINTED*/(m))
+#define MTRACE(m) ((void)/*LINTED*/(m))
 #endif /* ifdef NS_CLIENT_TRACE */
 
 #define TCP_CLIENT(c) (((c)->attributes & NS_CLIENTATTR_TCP) != 0)
@@ -126,7 +126,7 @@
  * Number of tasks to be used by clients - those are used only when recursing
  */
 
-#if defined(_WIN32) && !defined(_WIN64)
+#if (defined(_WIN32) && !defined(_WIN64)) || !defined(_LP64)
 LIBNS_EXTERNAL_DATA atomic_uint_fast32_t ns_client_requests;
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
 LIBNS_EXTERNAL_DATA atomic_uint_fast64_t ns_client_requests;
@@ -2334,6 +2334,8 @@ ns__client_setup(ns_client_t *client, ns
 		 * Retain these values from the existing client, but
 		 * zero every thing else.
 		 */
+#ifndef __lint__
+/* XXX: bug ? */
 		*client = (ns_client_t){ .magic = 0,
 					 .mctx = oldmctx,
 					 .manager = oldmgr,
@@ -2342,6 +2344,7 @@ ns__client_setup(ns_client_t *client, ns
 					 .sendbuf = sendbuf,
 					 .message = message,
 					 .query = query };
+#endif
 	}
 
 	client->state = NS_CLIENTSTATE_INACTIVE;
