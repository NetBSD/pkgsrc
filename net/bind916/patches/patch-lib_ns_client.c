$NetBSD: patch-lib_ns_client.c,v 1.5 2021/10/24 06:40:28 taca Exp $

Use 32-bit atomic integers for !_LP64 platforms.

--- lib/ns/client.c.orig	2021-09-07 09:37:05.000000000 +0000
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
 LIBNS_EXTERNAL_DATA atomic_uint_fast32_t ns_client_requests =
 	ATOMIC_VAR_INIT(0);
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
