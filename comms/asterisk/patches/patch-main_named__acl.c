$NetBSD: patch-main_named__acl.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- main/named_acl.c.orig	2012-12-06 17:28:35.000000000 +0000
+++ main/named_acl.c
@@ -309,11 +309,15 @@ static struct named_acl *named_acl_find_
 	return acl;
 }
 
+RAII_DECL(struct named_acl_config *, cfg, ao2_cleanup);
+RAII_DECL(struct named_acl *, named_acl, ao2_cleanup);
+RAII_DECL(struct named_acl *, realtime_acl, ao2_cleanup);
+
 struct ast_ha *ast_named_acl_find(const char *name, int *is_realtime, int *is_undefined) {
 	struct ast_ha *ha = NULL;
 
-	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct named_acl *, named_acl, NULL, ao2_cleanup);
+	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct named_acl *, named_acl, NULL);
 
 	if (is_realtime) {
 		*is_realtime = 0;
@@ -333,7 +337,7 @@ struct ast_ha *ast_named_acl_find(const 
 
 	/* If a named ACL couldn't be retrieved locally, we need to try realtime storage. */
 	if (!named_acl) {
-		RAII_VAR(struct named_acl *, realtime_acl, NULL, ao2_cleanup);
+		RAII_VAR(struct named_acl *, realtime_acl, NULL);
 
 		/* Attempt to create from realtime */
 		if ((realtime_acl = named_acl_find_realtime(name))) {
@@ -441,8 +445,8 @@ static void cli_display_named_acl(int fd
 	int ha_index = 0;
 	int is_realtime = 0;
 
-	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct named_acl *, named_acl, NULL, ao2_cleanup);
+	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct named_acl *, named_acl, NULL);
 
 	/* If the configuration or the configuration's named_acl_list is unavailable, abort. */
 	if ((!cfg) || (!cfg->named_acl_list)) {
@@ -481,7 +485,7 @@ static void cli_display_named_acl_list(i
 {
 	struct ao2_iterator i;
 	void *o;
-	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals));
 
 	ast_cli(fd, "\nacl\n---\n");
 
@@ -503,7 +507,7 @@ static void cli_display_named_acl_list(i
 /* \brief ACL command show <name> */
 static char *handle_show_named_acl_cmd(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct named_acl_config *, cfg, ao2_global_obj_ref(globals));
 	int length;
 	int which;
 	struct ao2_iterator i;
