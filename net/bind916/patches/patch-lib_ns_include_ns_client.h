$NetBSD: patch-lib_ns_include_ns_client.h,v 1.1.8.1 2021/08/28 09:22:55 bsiegert Exp $

Use 32-bit atomic integers for !_LP64 platforms.

--- lib/ns/include/ns/client.h.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/ns/include/ns/client.h
@@ -271,7 +271,7 @@ struct ns_client {
  */
 #define NS_FAILCACHE_CD 0x01
 
-#if defined(_WIN32) && !defined(_WIN64)
+#if (defined(_WIN32) && !defined(_WIN64)) || !defined(_LP64)
 LIBNS_EXTERNAL_DATA extern atomic_uint_fast32_t ns_client_requests;
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
 LIBNS_EXTERNAL_DATA extern atomic_uint_fast64_t ns_client_requests;
