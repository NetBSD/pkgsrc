$NetBSD: patch-main_udptl.c,v 1.2 2013/12/23 01:34:03 jnemeth Exp $

--- main/udptl.c.orig	2013-09-18 23:36:12.000000000 +0000
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
@@ -1417,11 +1419,13 @@ static int removed_options_handler(const
 	return 0;
 }
 
+RAII_DECL(struct udptl_config *, udptl_cfg, ao2_cleanup);
+
 static void __ast_udptl_reload(int reload)
 {
 	if (aco_process_config(&cfg_info, reload) == ACO_PROCESS_ERROR) {
 		if (!reload) {
-			RAII_VAR(struct udptl_config *, udptl_cfg, udptl_snapshot_alloc(), ao2_cleanup);
+			RAII_VAR(struct udptl_config *, udptl_cfg, udptl_snapshot_alloc());
 
 			if (aco_set_defaults(&general_option, "general", udptl_cfg->general)) {
 				ast_log(LOG_ERROR, "Failed to load udptl.conf and failed to initialize defaults.\n");
