$NetBSD: patch-main_features.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- main/features.c.orig	2018-05-07 17:28:38.342590540 +0000
+++ main/features.c
@@ -387,13 +387,13 @@ static void set_bridge_features_on_confi
 	for (feature = features; *feature; feature++) {
 		struct ast_flags *party;
 
-		if (isupper(*feature)) {
+		if (isupper((unsigned char)*feature)) {
 			party = &config->features_caller;
 		} else {
 			party = &config->features_callee;
 		}
 
-		switch (tolower(*feature)) {
+		switch (tolower((unsigned char)*feature)) {
 		case 't' :
 			ast_set_flag(party, AST_FEATURE_REDIRECT);
 			break;
