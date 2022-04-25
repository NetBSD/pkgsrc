$NetBSD: patch-src_libmongoc_tests_test-mongoc-stream-tls-error.c,v 1.1 2022/04/25 09:33:40 tnn Exp $

match ifdef around test_mongoc_tls_hangup implementation

--- src/libmongoc/tests/test-mongoc-stream-tls-error.c.orig	2021-07-06 20:11:18.000000000 +0000
+++ src/libmongoc/tests/test-mongoc-stream-tls-error.c
@@ -389,7 +389,7 @@ test_stream_tls_error_install (TestSuite
 {
 #if !defined(MONGOC_ENABLE_SSL_SECURE_CHANNEL) && \
    !defined(MONGOC_ENABLE_SSL_LIBRESSL)
-#if !defined(__APPLE__)
+#if !defined(__sun) && !defined(__APPLE__)
    TestSuite_Add (suite, "/TLS/hangup", test_mongoc_tls_hangup);
 #endif
 
