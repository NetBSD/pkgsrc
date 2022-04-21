$NetBSD: patch-lib_ns_client.c,v 1.6 2022/04/21 14:14:46 taca Exp $

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
@@ -128,7 +128,7 @@
  * Number of tasks to be used by clients - those are used only when recursing
  */
 
-#if defined(_WIN32) && !defined(_WIN64)
+#if defined(_WIN32) && !defined(_WIN64) || !defined(_LP64)
 LIBNS_EXTERNAL_DATA atomic_uint_fast32_t ns_client_requests = 0;
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
 LIBNS_EXTERNAL_DATA atomic_uint_fast64_t ns_client_requests = 0;
