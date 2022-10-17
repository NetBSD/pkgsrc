$NetBSD: patch-dirmngr_server.c,v 1.1 2022/10/17 09:13:18 adam Exp $

Fix building with LDAP support disabled.

--- dirmngr/server.c.orig	2022-10-17 07:38:14.000000000 +0000
+++ dirmngr/server.c
@@ -3135,7 +3135,9 @@ start_command_handler (assuan_fd_t fd, u
                ctrl->refcount);
   else
     {
+#if USE_LDAP
       ks_ldap_free_state (ctrl->ks_get_state);
+#endif /*USE_LDAP*/
       ctrl->ks_get_state = NULL;
       release_ctrl_ocsp_certs (ctrl);
       xfree (ctrl->server_local);
