$NetBSD: patch-lib_ext_wocky_tests_wocky-test-sasl-auth-server.c,v 1.1 2011/11/27 19:35:28 joerg Exp $

--- lib/ext/wocky/tests/wocky-test-sasl-auth-server.c.orig	2011-11-27 01:52:00.000000000 +0000
+++ lib/ext/wocky/tests/wocky-test-sasl-auth-server.c
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
 
