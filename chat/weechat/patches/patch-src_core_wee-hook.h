$NetBSD: patch-src_core_wee-hook.h,v 1.1.2.2 2011/03/09 19:11:19 tron Exp $

Fix for http://secunia.com/advisories/43543/

--- src/core/wee-hook.h.orig	2011-01-01 13:48:19.000000000 +0000
+++ src/core/wee-hook.h
@@ -202,10 +202,15 @@ typedef int (t_hook_callback_connect)(vo
                                       const char *ip_address);
 
 #ifdef HAVE_GNUTLS
+enum t_gnutls_cb_mode {
+    GNUTLS_CB_MODE_SETCERT,
+    GNUTLS_CB_MODE_VERIFY
+};
 typedef int (gnutls_callback_t)(void *data, gnutls_session_t tls_session,
                                 const gnutls_datum_t *req_ca, int nreq,
                                 const gnutls_pk_algorithm_t *pk_algos,
-                                int pk_algos_len, gnutls_retr_st *answer);
+                                int pk_algos_len, gnutls_retr_st *answer,
+                                enum t_gnutls_cb_mode cbmode);
 #endif
 
 struct t_hook_connect
@@ -416,6 +421,7 @@ extern int hook_connect_gnutls_set_certi
                                                  const gnutls_pk_algorithm_t *pk_algos,
                                                  int pk_algos_len,
                                                  gnutls_retr_st *answer);
+extern int hook_connect_gnutls_verify_certificates (gnutls_session_t tls_session);
 #endif
 extern struct t_hook *hook_print (struct t_weechat_plugin *plugin,
                                   struct t_gui_buffer *buffer,
