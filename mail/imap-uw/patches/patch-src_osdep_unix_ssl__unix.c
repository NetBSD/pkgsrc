$NetBSD: patch-src_osdep_unix_ssl__unix.c,v 1.2 2018/04/16 21:27:57 christos Exp $

Description: Support OpenSSL 1.1
 When building with OpenSSL 1.1 and newer, use the new built-in
 hostname verification instead of code that doesn't compile due to
 structs having been made opaque.
Bug-Debian: https://bugs.debian.org/828589

--- src/osdep/unix/ssl_unix.c.orig	2011-07-23 00:20:10.000000000 +0000
+++ src/osdep/unix/ssl_unix.c	2018-04-16 17:20:28.991950059 -0400
@@ -219,16 +219,28 @@
     (sslclientkey_t) mail_parameters (NIL,GET_SSLCLIENTKEY,NIL);
   if (ssl_last_error) fs_give ((void **) &ssl_last_error);
   ssl_last_host = host;
-  if (!(stream->context = SSL_CTX_new ((flags & NET_TLSCLIENT) ?
-				       TLSv1_client_method () :
-				       SSLv23_client_method ())))
+  if (!(stream->context = SSL_CTX_new (
+#if OPENSSL_VERSION_NUMBER < 0x10100000UL
+  (flags & NET_TLSCLIENT) ?  TLSv1_client_method () : SSLv23_client_method ()
+#else
+  TLS_client_method()
+#endif
+  )))
     return "SSL context failed";
   SSL_CTX_set_options (stream->context,0);
 				/* disable certificate validation? */
   if (flags & NET_NOVALIDATECERT)
     SSL_CTX_set_verify (stream->context,SSL_VERIFY_NONE,NIL);
-  else SSL_CTX_set_verify (stream->context,SSL_VERIFY_PEER,ssl_open_verify);
+  else {
+#if OPENSSL_VERSION_NUMBER >= 0x10100000      
+      X509_VERIFY_PARAM *param = SSL_CTX_get0_param(stream->context);
+      X509_VERIFY_PARAM_set_hostflags(param, X509_CHECK_FLAG_NO_PARTIAL_WILDCARDS);
+      X509_VERIFY_PARAM_set1_host(param, host, 0);
+#endif
+
+      SSL_CTX_set_verify (stream->context,SSL_VERIFY_PEER,ssl_open_verify);
 				/* set default paths to CAs... */
+  }
   SSL_CTX_set_default_verify_paths (stream->context);
 				/* ...unless a non-standard path desired */
   if (s = (char *) mail_parameters (NIL,GET_SSLCAPATH,NIL))
@@ -266,6 +278,7 @@
   if (SSL_write (stream->con,"",0) < 0)
     return ssl_last_error ? ssl_last_error : "SSL negotiation failed";
 				/* need to validate host names? */
+#if OPENSSL_VERSION_NUMBER < 0x10100000
   if (!(flags & NET_NOVALIDATECERT) &&
       (err = ssl_validate_cert (cert = SSL_get_peer_certificate (stream->con),
 				host))) {
@@ -275,6 +288,7 @@
     sprintf (tmp,"*%.128s: %.255s",err,cert ? cert->name : "???");
     return ssl_last_error = cpystr (tmp);
   }
+#endif
   return NIL;
 }
 
@@ -313,6 +327,7 @@
  * Returns: NIL if validated, else string of error message
  */
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000
 static char *ssl_validate_cert (X509 *cert,char *host)
 {
   int i,n;
@@ -342,6 +357,7 @@
   else ret = "Unable to locate common name in certificate";
   return ret;
 }
+#endif
 
 /* Case-independent wildcard pattern match
  * Accepts: base string
@@ -702,9 +718,13 @@
     if (stat (key,&sbuf)) strcpy (key,cert);
   }
 				/* create context */
-  if (!(stream->context = SSL_CTX_new (start_tls ?
-				       TLSv1_server_method () :
-				       SSLv23_server_method ())))
+  if (!(stream->context = SSL_CTX_new (
+#if OPENSSL_VERSION_NUMBER < 0x10100000UL
+  start_tls ? TLSv1_server_method () : SSLv23_server_method ()
+#else
+  TLS_server_method ()
+#endif
+  )))
     syslog (LOG_ALERT,"Unable to create SSL context, host=%.80s",
 	    tcp_clienthost ());
   else {			/* set context options */
@@ -772,17 +792,35 @@
 {
   unsigned long i;
   static RSA *key = NIL;
-  if (!key) {			/* if don't have a key already */
-				/* generate key */
-    if (!(key = RSA_generate_key (export ? keylength : 1024,RSA_F4,NIL,NIL))) {
-      syslog (LOG_ALERT,"Unable to generate temp key, host=%.80s",
-	      tcp_clienthost ());
-      while (i = ERR_get_error ())
-	syslog (LOG_ALERT,"SSL error status: %s",ERR_error_string (i,NIL));
-      exit (1);
-    }
-  }
-  return key;
+  static BIGNUM *ebn = NIL;
+
+  if (key)
+     return key;
+
+  key = RSA_new ();
+  if (!key)			/* if don't have a key already */
+    goto out;
+
+  ebn = BN_new ();
+  if (!ebn)
+    goto out;
+  BN_set_word (ebn, RSA_F4);
+
+  if (!RSA_generate_key_ex (key, export ? keylength : 1024, ebn, NIL))
+    goto out;
+  BN_free (ebn);
+   return key;
+
+out:
+  if (key)
+    RSA_free (key);
+  if (ebn)
+    BN_free (ebn);
+  syslog (LOG_ALERT,"Unable to generate temp key, host=%.80s",
+          tcp_clienthost ());
+  while (i = ERR_get_error ())
+    syslog (LOG_ALERT,"SSL error status: %s",ERR_error_string (i,NIL));
+  exit (1);
 }
 
 /* Wait for stdin input
