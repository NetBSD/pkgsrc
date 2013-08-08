$NetBSD: patch-apps_confbridge_conf__config__parser.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- apps/confbridge/conf_config_parser.c.orig	2013-02-26 15:24:35.000000000 +0000
+++ apps/confbridge/conf_config_parser.c
@@ -613,6 +613,8 @@ static int add_menu_entry(struct conf_me
 	return 0;
 }
 
+RAII_DECL(struct confbridge_cfg *, cfg, ao2_cleanup);
+
 static char *complete_user_profile_name(const char *line, const char *word, int pos, int state)
 {
 	int which = 0;
@@ -620,7 +622,7 @@ static char *complete_user_profile_name(
 	int wordlen = strlen(word);
 	struct ao2_iterator i;
 	struct user_profile *u_profile = NULL;
-	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle), ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle));
 
 	if (!cfg) {
 		return NULL;
@@ -644,7 +646,7 @@ static char *handle_cli_confbridge_show_
 {
 	struct ao2_iterator it;
 	struct user_profile *u_profile;
-	RAII_VAR(struct confbridge_cfg *, cfg, NULL, ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, NULL);
 
 	switch (cmd) {
 	case CLI_INIT:
@@ -770,7 +772,7 @@ static char *complete_bridge_profile_nam
 	int wordlen = strlen(word);
 	struct ao2_iterator i;
 	struct bridge_profile *b_profile = NULL;
-	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle), ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle));
 
 	if (!cfg) {
 		return NULL;
@@ -794,7 +796,7 @@ static char *handle_cli_confbridge_show_
 {
 	struct ao2_iterator it;
 	struct bridge_profile *b_profile;
-	RAII_VAR(struct confbridge_cfg *, cfg, NULL, ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, NULL);
 
 	switch (cmd) {
 	case CLI_INIT:
@@ -936,7 +938,7 @@ static char *complete_menu_name(const ch
 	int wordlen = strlen(word);
 	struct ao2_iterator i;
 	struct conf_menu *menu = NULL;
-	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle), ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle));
 
 	if (!cfg) {
 		return NULL;
@@ -960,7 +962,7 @@ static char *handle_cli_confbridge_show_
 {
 	struct ao2_iterator it;
 	struct conf_menu *menu;
-	RAII_VAR(struct confbridge_cfg *, cfg, NULL, ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, NULL);
 
 	switch (cmd) {
 	case CLI_INIT:
@@ -989,10 +991,12 @@ static char *handle_cli_confbridge_show_
 	return CLI_SUCCESS;
 }
 
+RAII_DECL(struct conf_menu *, menu, ao2_cleanup);
+
 static char *handle_cli_confbridge_show_menu(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct conf_menu *, menu, NULL, ao2_cleanup);
-	RAII_VAR(struct confbridge_cfg *, cfg, NULL, ao2_cleanup);
+	RAII_VAR(struct conf_menu *, menu, NULL);
+	RAII_VAR(struct confbridge_cfg *, cfg, NULL);
 	struct conf_menu_entry *menu_entry = NULL;
 	struct conf_menu_action *menu_action = NULL;
 
@@ -1285,10 +1289,13 @@ static int menu_option_handler(const str
 	return 0;
 }
 
+RAII_DECL(struct user_profile *, user_profile, ao2_cleanup);
+RAII_DECL(struct bridge_profile *, bridge_profile, ao2_cleanup);
+
 static int verify_default_profiles(void)
 {
-	RAII_VAR(struct user_profile *, user_profile, NULL, ao2_cleanup);
-	RAII_VAR(struct bridge_profile *, bridge_profile, NULL, ao2_cleanup);
+	RAII_VAR(struct user_profile *, user_profile, NULL);
+	RAII_VAR(struct bridge_profile *, bridge_profile, NULL);
 	struct confbridge_cfg *cfg = aco_pending_config(&cfg_info);
 
 	if (!cfg) {
@@ -1400,7 +1407,7 @@ const struct user_profile *conf_find_use
 	struct user_profile *tmp2;
 	struct ast_datastore *datastore = NULL;
 	struct func_confbridge_data *b_data = NULL;
-	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle), ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle));
 
 	if (!cfg) {
 		return NULL;
@@ -1454,7 +1461,7 @@ const struct bridge_profile *conf_find_b
 	struct bridge_profile *tmp2;
 	struct ast_datastore *datastore = NULL;
 	struct func_confbridge_data *b_data = NULL;
-	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle), ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle));
 
 	if (!cfg) {
 		return NULL;
@@ -1558,7 +1565,7 @@ int conf_set_menu_to_user(const char *me
 {
 	struct conf_menu *menu;
 	struct conf_menu_entry *menu_entry = NULL;
-	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle), ao2_cleanup);
+	RAII_VAR(struct confbridge_cfg *, cfg, ao2_global_obj_ref(cfg_handle));
 
 	if (!cfg) {
 		return -1;
