$NetBSD: patch-main_config__options.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- main/config_options.c.orig	2012-10-02 01:27:19.000000000 +0000
+++ main/config_options.c
@@ -343,8 +343,10 @@ static int is_preload(struct aco_file *f
 	return 0;
 }
 
+RAII_DECL(void *, new_item, ao2_cleanup);
+
 static int process_category(struct ast_config *cfg, struct aco_info *info, struct aco_file *file, const char *cat, int preload) {
-	RAII_VAR(void *, new_item, NULL, ao2_cleanup);
+	RAII_VAR(void *, new_item, NULL);
 	struct aco_type *type;
 	/* For global types, field is the global option struct. For non-global, it is the container for items.
 	 * We do not grab a reference to these objects, as the info already holds references to them. This
@@ -556,9 +558,12 @@ end:
 	ao2_cleanup(info->internal->pending);
 	return res;
 }
+
+RAII_DECL(struct aco_option *, opt, ao2_cleanup);
+
 int aco_process_var(struct aco_type *type, const char *cat, struct ast_variable *var, void *obj)
 {
-	RAII_VAR(struct aco_option *, opt, aco_option_find(type, var->name), ao2_cleanup);
+	RAII_VAR(struct aco_option *, opt, aco_option_find(type, var->name));
 	if (opt && opt->deprecated && !ast_strlen_zero(opt->aliased_to)) {
 		const char *alias = ast_strdupa(opt->aliased_to);
 		ast_log(LOG_WARNING, "At line %d of %s option '%s' is deprecated. Use '%s' instead\n", var->lineno, var->file, var->name, alias);
@@ -682,6 +687,8 @@ void aco_info_destroy(struct aco_info *i
 	}
 }
 
+RAII_DECL(struct ast_variable *, var, ast_variables_destroy);
+
 int aco_set_defaults(struct aco_type *type, const char *category, void *obj)
 {
 	struct aco_option *opt;
@@ -690,7 +697,7 @@ int aco_set_defaults(struct aco_type *ty
 	iter = ao2_iterator_init(type->internal->opts, 0);
 
 	while ((opt = ao2_iterator_next(&iter))) {
-		RAII_VAR(struct ast_variable *, var, NULL, ast_variables_destroy);
+		RAII_VAR(struct ast_variable *, var, NULL);
 
 		if (ast_strlen_zero(opt->default_val)) {
 			ao2_ref(opt, -1);
