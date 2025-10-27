$NetBSD: patch-res_res__musiconhold.c,v 1.1 2025/10/27 06:58:40 jnemeth Exp $

--- res/res_musiconhold.c.orig	2025-10-15 17:01:28.000000000 +0000
+++ res/res_musiconhold.c
@@ -1223,7 +1223,7 @@ static void moh_parse_options(struct ast
 		} else if (!strcasecmp(var->name, "announcement")) {
 			ast_copy_string(mohclass->announcement, var->value, sizeof(mohclass->announcement));
 			ast_set_flag(mohclass, MOH_ANNOUNCEMENT);
-		} else if (!strcasecmp(var->name, "digit") && (isdigit(*var->value) || strchr("*#", *var->value))) {
+		} else if (!strcasecmp(var->name, "digit") && (isdigit((unsigned char)*var->value) || strchr("*#", *var->value))) {
 			mohclass->digit = *var->value;
 		} else if (!strcasecmp(var->name, "sort")) {
 			if (!strcasecmp(var->value, "random")) {
