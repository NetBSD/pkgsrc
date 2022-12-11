$NetBSD: patch-lib_ns_client.c,v 1.1 2022/12/11 01:57:55 sekiya Exp $

Use 32-bit atomic integers for !_LP64 platforms.

--- lib/ns/client.c.orig	2022-04-11 15:28:12.000000000 +0000
+++ lib/ns/client.c
@@ -89,8 +89,8 @@
 	isc_log_write(ns_lctx, NS_LOGCATEGORY_CLIENT, NS_LOGMODULE_CLIENT, \
 		      ISC_LOG_DEBUG(3), "clientmgr @%p: %s", manager, (m))
 #else /* ifdef NS_CLIENT_TRACE */
-#define CTRACE(m) ((void)(m))
-#define MTRACE(m) ((void)(m))
+#define CTRACE(m) ((void)/*LINTED*/(m))
+#define MTRACE(m) ((void)/*LINTED*/(m))
 #endif /* ifdef NS_CLIENT_TRACE */
 
 #define TCP_CLIENT(c) (((c)->attributes & NS_CLIENTATTR_TCP) != 0)
