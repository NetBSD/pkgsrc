--- qt/src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslsocket_openssl_symbols.cpp	2020-04-24 02:04:11.900228983 +0200
@@ -116,11 +116,13 @@
 DEFINEFUNC3(int, BIO_read, BIO *a, a, void *b, b, int c, c, return -1, return)
 DEFINEFUNC(BIO_METHOD *, BIO_s_mem, void, DUMMYARG, return 0, return)
 DEFINEFUNC3(int, BIO_write, BIO *a, a, const void *b, b, int c, c, return -1, return)
 DEFINEFUNC(int, BN_num_bits, const BIGNUM *a, a, return 0, return)
+#if  OPENSSL_VERSION_NUMBER < 0x10101000L
 DEFINEFUNC(int, CRYPTO_num_locks, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(void, CRYPTO_set_locking_callback, void (*a)(int, int, const char *, int), a, return, DUMMYARG)
 DEFINEFUNC(void, CRYPTO_set_id_callback, unsigned long (*a)(), a, return, DUMMYARG)
+#endif
 DEFINEFUNC(void, CRYPTO_free, void *a, a, return, DUMMYARG)
 DEFINEFUNC(void, DSA_free, DSA *a, a, return, DUMMYARG)
 #if  OPENSSL_VERSION_NUMBER < 0x00908000L
 DEFINEFUNC3(X509 *, d2i_X509, X509 **a, a, unsigned char **b, b, long c, c, return 0, return)
@@ -156,14 +158,21 @@
 DEFINEFUNC2(int, PEM_write_bio_RSA_PUBKEY, BIO *a, a, RSA *b, b, return 0, return)
 DEFINEFUNC2(void, RAND_seed, const void *a, a, int b, b, return, DUMMYARG)
 DEFINEFUNC(int, RAND_status, void, DUMMYARG, return -1, return)
 DEFINEFUNC(void, RSA_free, RSA *a, a, return, DUMMYARG)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+DEFINEFUNC(int, OPENSSL_sk_num, STACK *a, a, return -1, return)
+DEFINEFUNC2(void, OPENSSL_sk_pop_free, STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
+DEFINEFUNC(void, OPENSSL_sk_free, _STACK *a, a, return, DUMMYARG)
+DEFINEFUNC2(void *, OPENSSL_sk_value, STACK *a, a, int b, b, return 0, return)
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
 DEFINEFUNC(int, sk_num, STACK *a, a, return -1, return)
 DEFINEFUNC2(void, sk_pop_free, STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
 DEFINEFUNC(void, sk_free, _STACK *a, a, return, DUMMYARG)
 DEFINEFUNC2(void *, sk_value, STACK *a, a, int b, b, return 0, return)
 #else
+DEFINEFUNC(int, sk_num, STACK *a, a, return -1, return)
+DEFINEFUNC2(void, sk_pop_free, STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
 DEFINEFUNC(void, sk_free, STACK *a, a, return, DUMMYARG)
 DEFINEFUNC2(char *, sk_value, STACK *a, a, int b, b, return 0, return)
 #endif
 DEFINEFUNC(int, SSL_accept, SSL *a, a, return -1, return)
@@ -212,10 +221,14 @@
 DEFINEFUNC(long, SSL_get_verify_result, const SSL *a, a, return -1, return)
 #else
 DEFINEFUNC(long, SSL_get_verify_result, SSL *a, a, return -1, return)
 #endif
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+DEFINEFUNC(int, OPENSSL_init_ssl, void, DUMMYARG, return -1, return)
+#else
 DEFINEFUNC(int, SSL_library_init, void, DUMMYARG, return -1, return)
 DEFINEFUNC(void, SSL_load_error_strings, void, DUMMYARG, return, DUMMYARG)
+#endif
 DEFINEFUNC(SSL *, SSL_new, SSL_CTX *a, a, return 0, return)
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
 DEFINEFUNC4(long, SSL_ctrl, SSL *a, a, int cmd, cmd, long larg, larg, void *parg, parg, return -1, return)
 #endif
@@ -223,9 +236,14 @@
 DEFINEFUNC3(void, SSL_set_bio, SSL *a, a, BIO *b, b, BIO *c, c, return, DUMMYARG)
 DEFINEFUNC(void, SSL_set_accept_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(void, SSL_set_connect_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(int, SSL_shutdown, SSL *a, a, return -1, return)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+DEFINEFUNC(const SSL_METHOD *, TLSv1_client_method, DUMMYARG, DUMMYARG, return 0, return)
+DEFINEFUNC(const SSL_METHOD *, TLS_client_method, DUMMYARG, DUMMYARG, return 0, return)
+DEFINEFUNC(const SSL_METHOD *, TLSv1_server_method, DUMMYARG, DUMMYARG, return 0, return)
+DEFINEFUNC(const SSL_METHOD *, TLS_server_method, DUMMYARG, DUMMYARG, return 0, return)
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
 DEFINEFUNC(const SSL_METHOD *, SSLv3_client_method, DUMMYARG, DUMMYARG, return 0, return)
@@ -273,20 +291,32 @@
 DEFINEFUNC2(int, X509_STORE_CTX_set_purpose, X509_STORE_CTX *a, a, int b, b, return -1, return)
 DEFINEFUNC(int, X509_STORE_CTX_get_error, X509_STORE_CTX *a, a, return -1, return)
 DEFINEFUNC(int, X509_STORE_CTX_get_error_depth, X509_STORE_CTX *a, a, return -1, return)
 DEFINEFUNC(X509 *, X509_STORE_CTX_get_current_cert, X509_STORE_CTX *a, a, return 0, return)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+DEFINEFUNC(STACK_OF(X509) *, X509_STORE_CTX_get0_chain, X509_STORE_CTX *a, a, return 0, return)
+#else
 DEFINEFUNC(STACK_OF(X509) *, X509_STORE_CTX_get_chain, X509_STORE_CTX *a, a, return 0, return)
+#endif
 DEFINEFUNC(X509_STORE_CTX *, X509_STORE_CTX_new, DUMMYARG, DUMMYARG, return 0, return)
 #ifdef SSLEAY_MACROS
 DEFINEFUNC2(int, i2d_DSAPrivateKey, const DSA *a, a, unsigned char **b, b, return -1, return)
 DEFINEFUNC2(int, i2d_RSAPrivateKey, const RSA *a, a, unsigned char **b, b, return -1, return)
 DEFINEFUNC3(RSA *, d2i_RSAPrivateKey, RSA **a, a, unsigned char **b, b, long c, c, return 0, return)
 DEFINEFUNC3(DSA *, d2i_DSAPrivateKey, DSA **a, a, unsigned char **b, b, long c, c, return 0, return)
 #endif
+#if  OPENSSL_VERSION_NUMBER >= 0x10101000L
+DEFINEFUNC2(int, OPENSSL_init_crypto, uint64_t opts, opts, const OPENSSL_INIT_SETTINGS *settings, settings, return 0, return)
+#else
 DEFINEFUNC(void, OPENSSL_add_all_algorithms_noconf, void, DUMMYARG, return, DUMMYARG)
 DEFINEFUNC(void, OPENSSL_add_all_algorithms_conf, void, DUMMYARG, return, DUMMYARG)
+#endif
 DEFINEFUNC3(int, SSL_CTX_load_verify_locations, SSL_CTX *ctx, ctx, const char *CAfile, CAfile, const char *CApath, CApath, return 0, return)
+#if  OPENSSL_VERSION_NUMBER >= 0x10101000L
+DEFINEFUNC(unsigned long, OpenSSL_version_num, void, DUMMYARG, return 0, return)
+#else
 DEFINEFUNC(long, SSLeay, void, DUMMYARG, return 0, return)
+#endif
 
 #ifdef Q_OS_SYMBIAN
 #define RESOLVEFUNC(func, ordinal, lib) \
     if (!(_q_##func = _q_PTR_##func(lib->resolve(#ordinal)))) \
@@ -613,11 +643,13 @@
     RESOLVEFUNC(BIO_s_mem, 251, libs.second )
     RESOLVEFUNC(BIO_write, 269, libs.second )
     RESOLVEFUNC(BN_num_bits, 387, libs.second )
     RESOLVEFUNC(CRYPTO_free, 469, libs.second )
+#if  OPENSSL_VERSION_NUMBER < 0x10101000L
     RESOLVEFUNC(CRYPTO_num_locks, 500, libs.second )
     RESOLVEFUNC(CRYPTO_set_id_callback, 513, libs.second )
     RESOLVEFUNC(CRYPTO_set_locking_callback, 516, libs.second )
+#endif
     RESOLVEFUNC(DSA_free, 594, libs.second )
     RESOLVEFUNC(ERR_error_string, 744, libs.second )
     RESOLVEFUNC(ERR_get_error, 749, libs.second )
     RESOLVEFUNC(EVP_des_ede3_cbc, 919, libs.second )
@@ -645,12 +677,19 @@
     RESOLVEFUNC(PEM_write_bio_RSA_PUBKEY, 1273, libs.second )
     RESOLVEFUNC(RAND_seed, 1426, libs.second )
     RESOLVEFUNC(RAND_status, 1429, libs.second )
     RESOLVEFUNC(RSA_free, 1450, libs.second )
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(OPENSSL_sk_free, 2571, libs.second )
+    RESOLVEFUNC(OPENSSL_sk_num, 2576, libs.second )
+    RESOLVEFUNC(OPENSSL_sk_pop_free, 2578, libs.second )    
+    RESOLVEFUNC(OPENSSL_sk_value, 2585, libs.second )
+#else
     RESOLVEFUNC(sk_free, 2571, libs.second )
     RESOLVEFUNC(sk_num, 2576, libs.second )
     RESOLVEFUNC(sk_pop_free, 2578, libs.second )    
     RESOLVEFUNC(sk_value, 2585, libs.second )
+#endif
     RESOLVEFUNC(SSL_CIPHER_description, 11, libs.first )
     RESOLVEFUNC(SSL_CTX_check_private_key, 21, libs.first )
     RESOLVEFUNC(SSL_CTX_ctrl, 22, libs.first )
     RESOLVEFUNC(SSL_CTX_free, 24, libs.first )
@@ -673,10 +712,14 @@
     RESOLVEFUNC(SSL_get_error, 110, libs.first )
     RESOLVEFUNC(SSL_get_peer_cert_chain, 117, libs.first )
     RESOLVEFUNC(SSL_get_peer_certificate, 118, libs.first )
     RESOLVEFUNC(SSL_get_verify_result, 132, libs.first )
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(OPENSSL_init_ssl, 137, libs.first )
+#else
     RESOLVEFUNC(SSL_library_init, 137, libs.first )
     RESOLVEFUNC(SSL_load_error_strings, 139, libs.first )
+#endif
     RESOLVEFUNC(SSL_new, 140, libs.first )
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
     RESOLVEFUNC(SSL_ctrl, 95, libs.first )
 #endif
@@ -685,16 +728,23 @@
     RESOLVEFUNC(SSL_set_bio, 149, libs.first )
     RESOLVEFUNC(SSL_set_connect_state, 152, libs.first )
     RESOLVEFUNC(SSL_shutdown, 173, libs.first )
     RESOLVEFUNC(SSL_write, 188, libs.first )
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(TLS_client_method, 189, libs.first )
+    RESOLVEFUNC(TLSv1_client_method, 198, libs.first )
+    RESOLVEFUNC(TLS_server_method, 191, libs.first )
+    RESOLVEFUNC(TLSv1_server_method, 200, libs.first )
+#else
     RESOLVEFUNC(SSLv2_client_method, 192, libs.first )
     RESOLVEFUNC(SSLv3_client_method, 195, libs.first )
     RESOLVEFUNC(SSLv23_client_method, 189, libs.first )
     RESOLVEFUNC(TLSv1_client_method, 198, libs.first )
     RESOLVEFUNC(SSLv2_server_method, 194, libs.first )
     RESOLVEFUNC(SSLv3_server_method, 197, libs.first )
     RESOLVEFUNC(SSLv23_server_method, 191, libs.first )
     RESOLVEFUNC(TLSv1_server_method, 200, libs.first )
+#endif
     RESOLVEFUNC(SSL_CTX_load_verify_locations, 34, libs.first )
     RESOLVEFUNC(X509_NAME_entry_count, 1821, libs.second )
     RESOLVEFUNC(X509_NAME_get_entry, 1823, libs.second )
     RESOLVEFUNC(X509_NAME_ENTRY_get_data, 1808, libs.second )
@@ -726,11 +776,16 @@
     RESOLVEFUNC(i2d_RSAPrivateKey, 2476, libs.second )
     RESOLVEFUNC(d2i_DSAPrivateKey, 2220, libs.second )
     RESOLVEFUNC(d2i_RSAPrivateKey, 2296, libs.second )
 #endif
+#if  OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(OPENSSL_init_crypto, 1153, libs.second )
+    RESOLVEFUNC(OpenSSL_version_num, 1504, libs.second )
+#else
     RESOLVEFUNC(OPENSSL_add_all_algorithms_noconf, 1153, libs.second )
     RESOLVEFUNC(OPENSSL_add_all_algorithms_conf, 1152, libs.second )
     RESOLVEFUNC(SSLeay, 1504, libs.second )
+#endif
 #else // Q_OS_SYMBIAN
 #ifdef SSLEAY_MACROS
     RESOLVEFUNC(ASN1_dup)
 #endif
@@ -746,11 +801,13 @@
     RESOLVEFUNC(BIO_s_mem)
     RESOLVEFUNC(BIO_write)
     RESOLVEFUNC(BN_num_bits)
     RESOLVEFUNC(CRYPTO_free)
+#if  OPENSSL_VERSION_NUMBER < 0x10101000L
     RESOLVEFUNC(CRYPTO_num_locks)
     RESOLVEFUNC(CRYPTO_set_id_callback)
     RESOLVEFUNC(CRYPTO_set_locking_callback)
+#endif
     RESOLVEFUNC(DSA_free)
     RESOLVEFUNC(ERR_error_string)
     RESOLVEFUNC(ERR_get_error)
     RESOLVEFUNC(EVP_des_ede3_cbc)
@@ -778,12 +835,19 @@
     RESOLVEFUNC(PEM_write_bio_RSA_PUBKEY)
     RESOLVEFUNC(RAND_seed)
     RESOLVEFUNC(RAND_status)
     RESOLVEFUNC(RSA_free)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(OPENSSL_sk_free)
+    RESOLVEFUNC(OPENSSL_sk_num)
+    RESOLVEFUNC(OPENSSL_sk_pop_free)
+    RESOLVEFUNC(OPENSSL_sk_value)
+#else
     RESOLVEFUNC(sk_free)
     RESOLVEFUNC(sk_num)
     RESOLVEFUNC(sk_pop_free)
     RESOLVEFUNC(sk_value)
+#endif
     RESOLVEFUNC(SSL_CIPHER_description)
     RESOLVEFUNC(SSL_CTX_check_private_key)
     RESOLVEFUNC(SSL_CTX_ctrl)
     RESOLVEFUNC(SSL_CTX_free)
@@ -806,10 +870,14 @@
     RESOLVEFUNC(SSL_get_error)
     RESOLVEFUNC(SSL_get_peer_cert_chain)
     RESOLVEFUNC(SSL_get_peer_certificate)
     RESOLVEFUNC(SSL_get_verify_result)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(OPENSSL_init_ssl)
+#else
     RESOLVEFUNC(SSL_library_init)
     RESOLVEFUNC(SSL_load_error_strings)
+#endif
     RESOLVEFUNC(SSL_new)
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
     RESOLVEFUNC(SSL_ctrl)
 #endif
@@ -818,8 +886,14 @@
     RESOLVEFUNC(SSL_set_bio)
     RESOLVEFUNC(SSL_set_connect_state)
     RESOLVEFUNC(SSL_shutdown)
     RESOLVEFUNC(SSL_write)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(TLS_client_method)
+    RESOLVEFUNC(TLSv1_client_method)
+    RESOLVEFUNC(TLS_server_method)
+    RESOLVEFUNC(TLSv1_server_method)
+#else
 #ifndef OPENSSL_NO_SSL2
     RESOLVEFUNC(SSLv2_client_method)
 #endif
     RESOLVEFUNC(SSLv3_client_method)
@@ -830,8 +904,9 @@
 #endif
     RESOLVEFUNC(SSLv3_server_method)
     RESOLVEFUNC(SSLv23_server_method)
     RESOLVEFUNC(TLSv1_server_method)
+#endif
     RESOLVEFUNC(X509_NAME_entry_count)
     RESOLVEFUNC(X509_NAME_get_entry)
     RESOLVEFUNC(X509_NAME_ENTRY_get_data)
     RESOLVEFUNC(X509_NAME_ENTRY_get_object)
@@ -845,9 +920,13 @@
     RESOLVEFUNC(X509_STORE_CTX_set_purpose)
     RESOLVEFUNC(X509_STORE_CTX_get_error)
     RESOLVEFUNC(X509_STORE_CTX_get_error_depth)
     RESOLVEFUNC(X509_STORE_CTX_get_current_cert)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(X509_STORE_CTX_get0_chain)
+#else
     RESOLVEFUNC(X509_STORE_CTX_get_chain)
+#endif
     RESOLVEFUNC(X509_cmp)
 #ifndef SSLEAY_MACROS
     RESOLVEFUNC(X509_dup)
 #endif
@@ -866,12 +945,17 @@
     RESOLVEFUNC(i2d_RSAPrivateKey)
     RESOLVEFUNC(d2i_DSAPrivateKey)
     RESOLVEFUNC(d2i_RSAPrivateKey)
 #endif
+    RESOLVEFUNC(SSL_CTX_load_verify_locations)
+#if  OPENSSL_VERSION_NUMBER >= 0x10101000L
+    RESOLVEFUNC(OPENSSL_init_crypto)
+    RESOLVEFUNC(OpenSSL_version_num)
+#else
     RESOLVEFUNC(OPENSSL_add_all_algorithms_noconf)
     RESOLVEFUNC(OPENSSL_add_all_algorithms_conf)
-    RESOLVEFUNC(SSL_CTX_load_verify_locations)
     RESOLVEFUNC(SSLeay)
+#endif
 #endif // Q_OS_SYMBIAN
     symbolsResolved = true;
     delete libs.first;
     delete libs.second;
