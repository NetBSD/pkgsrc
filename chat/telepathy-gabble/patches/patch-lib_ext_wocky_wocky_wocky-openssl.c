$NetBSD: patch-lib_ext_wocky_wocky_wocky-openssl.c,v 1.2 2012/02/16 15:50:16 hans Exp $

--- lib/ext/wocky/wocky/wocky-openssl.c.orig	2011-11-27 01:49:15.000000000 +0000
+++ lib/ext/wocky/wocky/wocky-openssl.c
@@ -165,7 +165,11 @@ struct _WockyTLSSession
   /* openssl structures */
   BIO *rbio;
   BIO *wbio;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+  const SSL_METHOD *method;
+#else
   SSL_METHOD *method;
+#endif
   SSL_CTX *ctx;
   SSL *ssl;
 };
@@ -685,7 +689,6 @@ wocky_tls_session_handshake (WockyTLSSes
 
       if (want_write)
         {
-          int ignored;
           gchar *wbuf;
           GOutputStream *out = g_io_stream_get_output_stream (session->stream);
           long wsize = BIO_get_mem_data (session->wbio, &wbuf);
@@ -694,7 +697,7 @@ wocky_tls_session_handshake (WockyTLSSes
           if (wsize > 0)
             sent = g_output_stream_write (out, wbuf, wsize, NULL, error);
           DEBUG ("sent %" G_GSSIZE_FORMAT " cipherbytes", sent);
-          ignored = BIO_reset (session->wbio);
+          (void) BIO_reset (session->wbio);
         }
 
       if (want_read)
@@ -824,7 +827,7 @@ wocky_tls_session_handshake_finish (Wock
 }
 
 #define CASELESS_CHARCMP(x, y) \
-  ((x) != '\0') && ((y) != '\0') && (toupper (x) == toupper (y))
+  ((x) != '\0') && ((y) != '\0') && (toupper ((unsigned char)x) == toupper ((unsigned char)y))
 
 static gboolean
 compare_wildcarded_hostname (const char *hostname, const char *certname)
@@ -890,7 +893,11 @@ check_peer_name (const char *target, X50
       {
         X509_EXTENSION *ext = sk_X509_EXTENSION_value (ci->extensions, i);
         ASN1_OBJECT *obj = X509_EXTENSION_get_object (ext);
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+        const X509V3_EXT_METHOD *convert = NULL;
+#else
         X509V3_EXT_METHOD *convert = NULL;
+#endif
         long ni = OBJ_obj2nid (obj);
         const guchar *p;
         char *value = NULL;
@@ -1513,8 +1520,6 @@ wocky_tls_session_write_ready (GObject  
   WockyTLSSession *session = WOCKY_TLS_SESSION (user_data);
   gint buffered = BIO_pending (session->wbio);
   gssize written;
-  /* memory BIO ops generally can't fail: suppress compiler/coverity warnings */
-  gint ignore_warning;
 
   if (tls_debug_level >= DEBUG_ASYNC_DETAIL_LEVEL)
     DEBUG ("");
@@ -1525,7 +1530,7 @@ wocky_tls_session_write_ready (GObject  
   if (written == buffered)
     {
       DEBUG ("%d bytes written, clearing write BIO", buffered);
-      ignore_warning = BIO_reset (session->wbio);
+      (void) BIO_reset (session->wbio);
       wocky_tls_session_try_operation (session, WOCKY_TLS_OP_WRITE);
     }
   else
@@ -1539,8 +1544,8 @@ wocky_tls_session_write_ready (GObject  
         {
           gchar *pending = g_memdup (buffer + written, psize);
 
-          ignore_warning = BIO_reset (session->wbio);
-          ignore_warning = BIO_write (session->wbio, pending, psize);
+          (void) BIO_reset (session->wbio);
+          (void) BIO_write (session->wbio, pending, psize);
           g_free (pending);
         }
 
@@ -1660,6 +1665,7 @@ set_dh_parameters (WockyTLSSession *sess
 static void
 set_ecdh_key (WockyTLSSession *session)
 {
+#ifndef OPENSSL_NO_EC
   EC_KEY *ecdh = EC_KEY_new_by_curve_name (NID_sect163r2);
   if (ecdh == NULL)
     {
@@ -1668,6 +1674,7 @@ set_ecdh_key (WockyTLSSession *session)
     }
   SSL_CTX_set_tmp_ecdh (session->ctx,ecdh);
   EC_KEY_free (ecdh);
+#endif
 }
 
 static void
