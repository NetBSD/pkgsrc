--- qt/src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslsocket_openssl_symbols_p.h	2020-04-24 02:00:16.877762168 +0200
@@ -212,11 +212,17 @@
 int q_BIO_read(BIO *a, void *b, int c);
 BIO_METHOD *q_BIO_s_mem();
 int q_BIO_write(BIO *a, const void *b, int c);
 int q_BN_num_bits(const BIGNUM *a);
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+#define q_CRYPTO_num_locks() 0
+#define q_CRYPTO_set_locking_callback(x)
+#define q_CRYPTO_set_id_callback(x)
+#else
 int q_CRYPTO_num_locks();
 void q_CRYPTO_set_locking_callback(void (*a)(int, int, const char *, int));
 void q_CRYPTO_set_id_callback(unsigned long (*a)());
+#endif
 void q_CRYPTO_free(void *a);
 void q_DSA_free(DSA *a);
 #if OPENSSL_VERSION_NUMBER >= 0x00908000L
 // 0.9.8 broke SC and BC by changing this function's signature.
@@ -257,14 +263,25 @@
 int q_PEM_write_bio_RSA_PUBKEY(BIO *a, RSA *b);
 void q_RAND_seed(const void *a, int b);
 int q_RAND_status();
 void q_RSA_free(RSA *a);
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+int q_OPENSSL_sk_num(STACK *a);
+void q_OPENSSL_sk_pop_free(STACK *a, void (*b)(void *));
+void q_OPENSSL_sk_free(_STACK *a);
+void * q_OPENSSL_sk_value(STACK *a, int b);
+#define q_sk_num q_OPENSSL_sk_num
+#define q_sk_pop_free q_OPENSSL_sk_pop_free
+#define q_sk_free q_OPENSSL_sk_free
+#define q_sk_value q_OPENSSL_sk_value
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
 int q_sk_num(STACK *a);
 void q_sk_pop_free(STACK *a, void (*b)(void *));
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
 void q_sk_free(_STACK *a);
 void * q_sk_value(STACK *a, int b);
 #else
+int q_sk_num(STACK *a);
+void q_sk_pop_free(STACK *a, void (*b)(void *));
 void q_sk_free(STACK *a);
 char * q_sk_value(STACK *a, int b);
 #endif
 int q_SSL_accept(SSL *a);
@@ -313,10 +330,16 @@
 long q_SSL_get_verify_result(const SSL *a);
 #else
 long q_SSL_get_verify_result(SSL *a);
 #endif
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+int q_OPENSSL_init_ssl();
+#define q_SSL_library_init q_OPENSSL_init_ssl
+#define q_SSL_load_error_strings() 
+#else
 int q_SSL_library_init();
 void q_SSL_load_error_strings();
+#endif
 SSL *q_SSL_new(SSL_CTX *a);
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
 long q_SSL_ctrl(SSL *ssl,int cmd, long larg, void *parg);
 #endif
@@ -324,9 +347,20 @@
 void q_SSL_set_bio(SSL *a, BIO *b, BIO *c);
 void q_SSL_set_accept_state(SSL *a);
 void q_SSL_set_connect_state(SSL *a);
 int q_SSL_shutdown(SSL *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+const SSL_METHOD *q_TLS_client_method();
+const SSL_METHOD *q_TLSv1_client_method();
+const SSL_METHOD *q_TLS_server_method();
+const SSL_METHOD *q_TLSv1_server_method();
+#define q_SSLv2_client_method q_TLS_client_method
+#define q_SSLv3_client_method q_TLS_client_method
+#define q_SSLv23_client_method q_TLS_client_method
+#define q_SSLv2_server_method q_TLS_server_method
+#define q_SSLv3_server_method q_TLS_server_method
+#define q_SSLv23_server_method q_TLS_server_method
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
 const SSL_METHOD *q_SSLv2_client_method();
 const SSL_METHOD *q_SSLv3_client_method();
 const SSL_METHOD *q_SSLv23_client_method();
 const SSL_METHOD *q_TLSv1_client_method();
@@ -398,8 +432,11 @@
 #define	q_PEM_write_bio_DSAPrivateKey(bp,x,enc,kstr,klen,cb,u) \
 		PEM_ASN1_write_bio((int (*)(void*, unsigned char**))q_i2d_DSAPrivateKey,PEM_STRING_DSA,\
 			bp,(char *)x,enc,kstr,klen,cb,u)
 #endif
+#ifndef SSL_CTRL_OPTIONS
+#define SSL_CTRL_OPTIONS 32
+#endif
 #define q_SSL_CTX_set_options(ctx,op) q_SSL_CTX_ctrl((ctx),SSL_CTRL_OPTIONS,(op),NULL)
 #define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_sk_num)(st)
 #define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_sk_value)(st, i)
 #define q_sk_GENERAL_NAME_num(st) q_SKM_sk_num(GENERAL_NAME, (st))
@@ -415,17 +452,37 @@
 #define q_EVP_PKEY_assign_RSA(pkey,rsa) q_EVP_PKEY_assign((pkey),EVP_PKEY_RSA,\
 					(char *)(rsa))
 #define q_EVP_PKEY_assign_DSA(pkey,dsa) q_EVP_PKEY_assign((pkey),EVP_PKEY_DSA,\
 					(char *)(dsa))
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+int q_OPENSSL_init_crypto(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
+#ifdef OPENSSL_LOAD_CONF
+#define q_OpenSSL_add_all_algorithms() \
+    q_OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS | \
+			  OPENSSL_INIT_ADD_ALL_DIGESTS | \
+			  OPENSSL_INIT_LOAD_CONFIG, NULL);
+#else
+#define q_OpenSSL_add_all_algorithms() \
+    q_OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS | \
+			  OPENSSL_INIT_ADD_ALL_DIGESTS, \
+			  NULL);
+#endif
+#else /* OPENSSL_VERSION_NUMBER < 0x10101000L */
 #ifdef OPENSSL_LOAD_CONF
 #define q_OpenSSL_add_all_algorithms() q_OPENSSL_add_all_algorithms_conf()
 #else
 #define q_OpenSSL_add_all_algorithms() q_OPENSSL_add_all_algorithms_noconf()
 #endif
 void q_OPENSSL_add_all_algorithms_noconf();
 void q_OPENSSL_add_all_algorithms_conf();
+#endif /* OPENSSL_VERSION_NUMBER */
 int q_SSL_CTX_load_verify_locations(SSL_CTX *ctx, const char *CAfile, const char *CApath);
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+unsigned long q_OpenSSL_version_num();
+#define q_SSLeay() q_OpenSSL_version_num()
+#else
 long q_SSLeay();
+#endif
 
 // Helper function
 class QDateTime;
 QDateTime q_getTimeFromASN1(const ASN1_TIME *aTime);
