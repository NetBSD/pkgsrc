$NetBSD: patch-lib_ssl.c,v 1.1 2020/03/19 11:30:26 nia Exp $

Bug-Debian: https://bugs.debian.org/828512
Description: Support OpenSSL 1.1 API changes
 SSL_CTX_set_tmp_rsa_callback() (used for export-weakened keys) no longer does anything.

Description: Disable SSL 3.0 on client as well as server side
Author: Magnus Holmgren <holmgren@debian.org>

--- lib/ssl.c.orig	2020-03-19 11:24:27.753715164 +0000
+++ lib/ssl.c
@@ -78,17 +78,6 @@ static void os_initialize_prng(struct ss
     int totbytes = 0;
     int bytes;
 
-    if (ssl_config->egd_socket) {
-        if ((bytes = RAND_egd(ssl_config->egd_socket)) == -1) {
-            log_fatal("EGD Socket %s failed", ssl_config->egd_socket);
-        } else {
-            totbytes += bytes;
-            log_debug("Snagged %d random bytes from EGD Socket %s",
-                      bytes, ssl_config->egd_socket);
-            goto SEEDED;        /* ditto */
-        }
-    }
-
     /* Try the good-old default /dev/urandom, if available  */
     totbytes += add_rand_file("/dev/urandom");
     if (prng_seeded(totbytes)) {
@@ -212,6 +201,8 @@ static int new_session_cb(SSL * ssl, SSL
     unsigned char *data = NULL, *asn;
     time_t expire;
     int ret = -1;
+    unsigned int session_id_length;
+    unsigned char *session_id = SSL_SESSION_get_id(sess, &session_id_length);
 
     if (!sess_dbopen)
         return 0;
@@ -241,8 +232,7 @@ static int new_session_cb(SSL * ssl, SSL
     if (data && len) {
         /* store the session in our database */
         do {
-            ret = DB->store(sessdb, (void *) sess->session_id,
-                            sess->session_id_length,
+            ret = DB->store(sessdb, (void *) session_id, session_id_length,
                             (void *) data, len + sizeof(time_t), NULL);
         }
         while (ret == MYDB_AGAIN);
@@ -255,8 +245,8 @@ static int new_session_cb(SSL * ssl, SSL
     if (ssl_verbose_logging) {
         int i;
         char idstr[SSL_MAX_SSL_SESSION_ID_LENGTH * 2 + 1];
-        for (i = 0; i < sess->session_id_length; i++)
-            sprintf(idstr + i * 2, "%02X", sess->session_id[i]);
+        for (i = 0; i < session_id_length; i++)
+            sprintf(idstr + i * 2, "%02X", session_id[i]);
 
         log_debug("new SSL session: id=%s, expire=%s, status=%s",
                   idstr, ctime(&expire), ret ? "failed" : "ok");
@@ -298,7 +288,10 @@ static void remove_session(unsigned char
  */
 static void remove_session_cb(SSL_CTX * ctx, SSL_SESSION * sess)
 {
-    remove_session(sess->session_id, sess->session_id_length);
+    unsigned int session_id_length;
+    unsigned char *session_id = SSL_SESSION_get_id(sess, &session_id_length);
+
+    remove_session(session_id, session_id_length);
 }
 
 /*
@@ -387,15 +380,16 @@ void ssl_context_init(struct ssl_config 
     SSL_load_error_strings();
 
     /* Set up client context: only used by accountd */
-    client_ctx = SSL_CTX_new(SSLv3_client_method());
+    client_ctx = SSL_CTX_new(SSLv23_client_method());
     SSL_CTX_set_session_cache_mode(client_ctx, SSL_SESS_CACHE_BOTH);
     SSL_CTX_set_info_callback(client_ctx, info_callback);
 #ifdef SSL_MODE_AUTO_RETRY
     SSL_CTX_set_mode(client_ctx, SSL_MODE_AUTO_RETRY);
 #endif
-
-    if (SSL_CTX_need_tmp_RSA(client_ctx))
-        SSL_CTX_set_tmp_rsa_callback(client_ctx, rsa_callback);
+    /* SSLv2 now obsolete */
+    SSL_CTX_set_options(client_ctx, SSL_OP_NO_SSLv2);
+    /* SSLv3 now also obsolete */
+    SSL_CTX_set_options(client_ctx, SSL_OP_NO_SSLv3);
 
     /* Don't bother with session cache for client side: not enough
      * connections to worry about caching */
@@ -420,6 +414,8 @@ void ssl_context_init(struct ssl_config 
 
     /* SSLv2 now obsolete */
     SSL_CTX_set_options(server_ctx, SSL_OP_NO_SSLv2);
+    /* SSLv3 now also obsolete */
+    SSL_CTX_set_options(server_ctx, SSL_OP_NO_SSLv3);
 
     /* Start off with the session cache disabled */
     SSL_CTX_set_session_cache_mode(server_ctx, SSL_SESS_CACHE_OFF);
@@ -503,10 +499,6 @@ void ssl_context_init(struct ssl_config 
         log_fatal("SSL_CTX_set_options(SSL_OP_CIPHER_SERVER_PREFERENCE)"
                   "failed");
 
-    /* Set up RSA temporary key callback routine */
-    if (SSL_CTX_need_tmp_RSA(server_ctx))
-        SSL_CTX_set_tmp_rsa_callback(server_ctx, rsa_callback);
-
     /* Initialise RSA temporary key (will take a couple of secs to complete) */
     ssl_init_rsakey(ssl_config);
 }
@@ -615,7 +607,7 @@ void *ssl_start_server(int fd, unsigned 
     else
         log_debug("SSL: No client certificate");
 
-    switch (ssl->session->ssl_version) {
+    switch (SSL_version(ssl)) {
     case SSL2_VERSION:
         ver = "SSLv2";
         break;
@@ -625,6 +617,12 @@ void *ssl_start_server(int fd, unsigned 
     case TLS1_VERSION:
         ver = "TLSv1";
         break;
+    case TLS1_1_VERSION:
+        ver = "TLSv1.1";
+        break;
+    case TLS1_2_VERSION:
+        ver = "TLSv1.2";
+        break;
     default:
         ver = "UNKNOWN";
     }
@@ -668,7 +666,7 @@ void *ssl_start_client(int fd, unsigned 
 
     /* Verify certificate here? Need local context to play with? */
 
-    switch (((SSL *) ssl)->session->ssl_version) {
+    switch (SSL_version(ssl)) {
     case SSL2_VERSION:
         ver = "SSLv2";
         break;
@@ -678,6 +676,12 @@ void *ssl_start_client(int fd, unsigned 
     case TLS1_VERSION:
         ver = "TLSv1";
         break;
+    case TLS1_1_VERSION:
+        ver = "TLSv1.1";
+        break;
+    case TLS1_2_VERSION:
+        ver = "TLSv1.2";
+        break;
     default:
         ver = "UNKNOWN";
     }
