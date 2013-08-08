$NetBSD: patch-apps_app__skel.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- apps/app_skel.c.orig	2012-06-07 20:32:07.000000000 +0000
+++ apps/app_skel.c
@@ -315,13 +315,17 @@ static void play_files_helper(struct ast
 	}
 }
 
+RAII_DECL(struct skel_config *, cfg, ao2_cleanup);
+RAII_DECL(struct skel_level *, level, ao2_cleanup);
+RAII_DECL(struct skel_current_game *, game, ao2_cleanup);
+
 static int app_exec(struct ast_channel *chan, const char *data)
 {
 	int win = 0;
 	uint32_t guesses;
-	RAII_VAR(struct skel_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct skel_level *, level, NULL, ao2_cleanup);
-	RAII_VAR(struct skel_current_game *, game, NULL, ao2_cleanup);
+	RAII_VAR(struct skel_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct skel_level *, level, NULL);
+	RAII_VAR(struct skel_current_game *, game, NULL);
 	char *parse, *opts[OPTION_ARG_ARRAY_SIZE];
 	struct ast_flags flags;
 	AST_DECLARE_APP_ARGS(args,
@@ -459,8 +463,8 @@ static void *skel_level_find(struct ao2_
  */
 static void *skel_find_or_create_state(const char *category)
 {
-	RAII_VAR(struct skel_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct skel_level *, level, NULL, ao2_cleanup);
+	RAII_VAR(struct skel_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct skel_level *, level, NULL);
 	if (!cfg || !cfg->levels || !(level = ao2_find(cfg->levels, category, OBJ_KEY))) {
 		return skel_state_alloc(category);
 	}
@@ -531,7 +535,7 @@ error:
 
 static char *handle_skel_show_config(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct skel_config *, cfg, NULL, ao2_cleanup);
+	RAII_VAR(struct skel_config *, cfg, NULL);
 
 	switch(cmd) {
 	case CLI_INIT:
@@ -591,7 +595,7 @@ static char *handle_skel_show_games(stru
 
 static char *handle_skel_show_levels(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct skel_config *, cfg, NULL, ao2_cleanup);
+	RAII_VAR(struct skel_config *, cfg, NULL);
 	struct ao2_iterator iter;
 	struct skel_level *level;
 
