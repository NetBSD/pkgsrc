$NetBSD: patch-lib_ext_wocky_wocky_wocky-openssl.c,v 1.1 2011/11/27 19:35:28 joerg Exp $

--- lib/ext/wocky/wocky/wocky-openssl.c.orig	2011-11-27 01:49:15.000000000 +0000
+++ lib/ext/wocky/wocky/wocky-openssl.c
@@ -165,7 +165,7 @@ struct _WockyTLSSession
   /* openssl structures */
   BIO *rbio;
   BIO *wbio;
-  SSL_METHOD *method;
+  const SSL_METHOD *method;
   SSL_CTX *ctx;
   SSL *ssl;
 };
@@ -824,7 +824,7 @@ wocky_tls_session_handshake_finish (Wock
 }
 
 #define CASELESS_CHARCMP(x, y) \
-  ((x) != '\0') && ((y) != '\0') && (toupper (x) == toupper (y))
+  ((x) != '\0') && ((y) != '\0') && (toupper ((unsigned char)x) == toupper ((unsigned char)y))
 
 static gboolean
 compare_wildcarded_hostname (const char *hostname, const char *certname)
@@ -890,7 +890,7 @@ check_peer_name (const char *target, X50
       {
         X509_EXTENSION *ext = sk_X509_EXTENSION_value (ci->extensions, i);
         ASN1_OBJECT *obj = X509_EXTENSION_get_object (ext);
-        X509V3_EXT_METHOD *convert = NULL;
+        const X509V3_EXT_METHOD *convert = NULL;
         long ni = OBJ_obj2nid (obj);
         const guchar *p;
         char *value = NULL;
