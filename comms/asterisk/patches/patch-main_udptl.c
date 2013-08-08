$NetBSD: patch-main_udptl.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- main/udptl.c.orig	2012-12-11 21:12:26.000000000 +0000
+++ main/udptl.c
@@ -952,6 +952,8 @@ unsigned int ast_udptl_get_far_max_ifp(s
 	return udptl->far_max_ifp;
 }
 
+RAII_DECL(struct udptl_config *, cfg, ao2_cleanup);
+
 struct ast_udptl *ast_udptl_new_with_bindaddr(struct ast_sched_context *sched, struct io_context *io, int callbackmode, struct ast_sockaddr *addr)
 {
 	struct ast_udptl *udptl;
@@ -959,7 +961,7 @@ struct ast_udptl *ast_udptl_new_with_bin
 	int startplace;
 	int i;
 	long int flags;
-	RAII_VAR(struct udptl_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct udptl_config *, cfg, ao2_global_obj_ref(globals));
 
 	if (!cfg || !cfg->general) {
 		ast_log(LOG_ERROR, "Could not access global udptl options!\n");
@@ -1352,7 +1354,7 @@ static char *handle_cli_udptl_set_debug(
 
 static char *handle_cli_show_config(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct udptl_config *, cfg, NULL, ao2_cleanup);
+	RAII_VAR(struct udptl_config *, cfg, NULL);
 
 	switch (cmd) {
 	case CLI_INIT:
