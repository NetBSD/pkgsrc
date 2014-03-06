$NetBSD: patch-lib_ext_wocky_tests_wocky-test-sasl-auth-server.c,v 1.2 2014/03/06 15:43:23 joerg Exp $

--- lib/ext/wocky/tests/wocky-test-sasl-auth-server.c.orig	2010-10-20 14:56:06.000000000 +0000
+++ lib/ext/wocky/tests/wocky-test-sasl-auth-server.c
@@ -154,7 +154,7 @@ test_sasl_auth_server_dispose (GObject *
   priv->stream = NULL;
 
 #ifdef HAVE_LIBSASL2
-  if (&priv->sasl_conn != NULL)
+  if (priv->sasl_conn != NULL)
     sasl_dispose (&priv->sasl_conn);
   priv->sasl_conn = NULL;
 #endif
@@ -929,8 +929,8 @@ test_sasl_auth_server_new (GIOStream *st
   static gboolean sasl_initialized = FALSE;
   int ret;
   static sasl_callback_t callbacks[] = {
-    { SASL_CB_LOG, test_sasl_server_auth_log, NULL },
-    { SASL_CB_GETOPT, test_sasl_server_auth_getopt, NULL },
+    { SASL_CB_LOG, (void *)test_sasl_server_auth_log, NULL },
+    { SASL_CB_GETOPT, (void *)test_sasl_server_auth_getopt, NULL },
     { SASL_CB_LIST_END, NULL, NULL },
   };
 
