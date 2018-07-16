$NetBSD: patch-res_res__musiconhold.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_musiconhold.c.orig	2018-05-07 17:40:09.242361670 +0000
+++ res/res_musiconhold.c
@@ -1071,7 +1071,7 @@ static void moh_parse_options(struct ast
 			ast_copy_string(mohclass->dir, var->value, sizeof(mohclass->dir));
 		} else if (!strcasecmp(var->name, "application")) {
 			ast_copy_string(mohclass->args, var->value, sizeof(mohclass->args));
-		} else if (!strcasecmp(var->name, "digit") && (isdigit(*var->value) || strchr("*#", *var->value))) {
+		} else if (!strcasecmp(var->name, "digit") && (isdigit((unsigned char)*var->value) || strchr("*#", *var->value))) {
 			mohclass->digit = *var->value;
 		} else if (!strcasecmp(var->name, "random")) {
 			static int deprecation_warning = 0;
@@ -1771,7 +1771,7 @@ static int load_moh_classes(int reload)
 			} else if (!strcasecmp(var->name, "announcement")) {
 				ast_copy_string(class->announcement, var->value, sizeof(class->announcement));
 				ast_set_flag(class, MOH_ANNOUNCEMENT);
-			} else if (!strcasecmp(var->name, "digit") && (isdigit(*var->value) || strchr("*#", *var->value))) {
+			} else if (!strcasecmp(var->name, "digit") && (isdigit((unsigned char)*var->value) || strchr("*#", *var->value))) {
 				class->digit = *var->value;
 			} else if (!strcasecmp(var->name, "random")) {
 				ast_set2_flag(class, ast_true(var->value), MOH_RANDOMIZE);
