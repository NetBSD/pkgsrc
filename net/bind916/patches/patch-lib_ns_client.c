$NetBSD: patch-lib_ns_client.c,v 1.4.2.2 2021/08/28 09:22:55 bsiegert Exp $

Use 32-bit atomic integers for !_LP64 platforms.

--- lib/ns/client.c.orig	2021-07-19 08:32:57.384417149 +0900
+++ lib/ns/client.c	2021-07-19 08:33:25.780329755 +0900
@@ -126,7 +126,7 @@
  * Number of tasks to be used by clients - those are used only when recursing
  */
 
-#if defined(_WIN32) && !defined(_WIN64)
+#if (defined(_WIN32) && !defined(_WIN64)) || !defined(_LP64)
 LIBNS_EXTERNAL_DATA atomic_uint_fast32_t ns_client_requests =
 	ATOMIC_VAR_INIT(0);
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
