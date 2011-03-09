$NetBSD: patch-src_core_wee-hook.c,v 1.1.2.2 2011/03/09 19:11:19 tron Exp $

Fix for http://secunia.com/advisories/43543/

--- src/core/wee-hook.c.orig	2011-01-02 18:05:16.000000000 +0000
+++ src/core/wee-hook.c
@@ -1700,6 +1700,38 @@ hook_connect (struct t_weechat_plugin *p
 }
 
 /*
+ * hook_connect_gnutls_verify_certificates: verify server certificate
+ */
+
+#ifdef HAVE_GNUTLS
+int
+hook_connect_gnutls_verify_certificates (gnutls_session_t tls_session)
+{
+    struct t_hook *ptr_hook;
+    int rc;
+    
+    rc = -1;
+    ptr_hook = weechat_hooks[HOOK_TYPE_CONNECT];
+    while (ptr_hook)
+    {
+        /* looking for the right hook using to the gnutls session pointer */
+        if (!ptr_hook->deleted
+            && HOOK_CONNECT(ptr_hook, gnutls_sess)
+            && (*(HOOK_CONNECT(ptr_hook, gnutls_sess)) == tls_session))
+        {
+            rc = (int) (HOOK_CONNECT(ptr_hook, gnutls_cb))
+                (ptr_hook->callback_data, tls_session, NULL, 0,
+                 NULL, 0, NULL, GNUTLS_CB_MODE_VERIFY);
+            break;
+        }
+        ptr_hook = ptr_hook->next_hook;
+    }
+    
+    return rc;
+}
+#endif
+
+/*
  * hook_connect_gnutls_set_certificates: set gnutls
  */
 
@@ -1725,7 +1757,7 @@ hook_connect_gnutls_set_certificates (gn
         {
             rc = (int) (HOOK_CONNECT(ptr_hook, gnutls_cb))
                 (ptr_hook->callback_data, tls_session, req_ca, nreq,
-                 pk_algos, pk_algos_len, answer);
+                 pk_algos, pk_algos_len, answer, GNUTLS_CB_MODE_SETCERT);
             break;
         }
         ptr_hook = ptr_hook->next_hook;
