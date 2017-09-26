$NetBSD: patch-tests_test-mongoc-stream-tls-error.c,v 1.1 2017/09/26 14:18:21 fhajny Exp $

Match conditioning on usage and definition.

--- tests/test-mongoc-stream-tls-error.c.orig	2017-09-07 23:03:30.000000000 +0000
+++ tests/test-mongoc-stream-tls-error.c
@@ -338,7 +338,7 @@ test_stream_tls_error_install (TestSuite
 {
 #if !defined(MONGOC_ENABLE_SSL_SECURE_CHANNEL) && \
    !defined(MONGOC_ENABLE_SSL_LIBRESSL)
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__sun)
    TestSuite_Add (suite, "/TLS/hangup", test_mongoc_tls_hangup);
 #endif
 
