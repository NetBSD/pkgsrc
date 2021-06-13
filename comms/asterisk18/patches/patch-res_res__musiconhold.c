$NetBSD: patch-res_res__musiconhold.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- res/res_musiconhold.c.orig	2021-03-04 16:46:08.000000000 +0000
+++ res/res_musiconhold.c
@@ -1153,7 +1153,7 @@ static void moh_parse_options(struct ast
 		} else if (!strcasecmp(var->name, "announcement")) {
 			ast_copy_string(mohclass->announcement, var->value, sizeof(mohclass->announcement));
 			ast_set_flag(mohclass, MOH_ANNOUNCEMENT);
-		} else if (!strcasecmp(var->name, "digit") && (isdigit(*var->value) || strchr("*#", *var->value))) {
+		} else if (!strcasecmp(var->name, "digit") && (isdigit((unsigned char)*var->value) || strchr("*#", *var->value))) {
 			mohclass->digit = *var->value;
 		} else if (!strcasecmp(var->name, "random")) {
 			static int deprecation_warning = 0;
