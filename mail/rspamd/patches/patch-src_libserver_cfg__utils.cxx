$NetBSD: patch-src_libserver_cfg__utils.cxx,v 1.1 2023/10/19 14:35:01 wiz Exp $

--- src/libserver/cfg_utils.cxx.orig	2023-10-07 13:52:02.000000000 +0000
+++ src/libserver/cfg_utils.cxx
@@ -135,14 +135,14 @@ struct rspamd_actions_list {
 	void sort()
 	{
 		std::sort(actions.begin(), actions.end(), [](const action_ptr &a1, const action_ptr &a2) -> bool {
-			if (!isnan(a1->threshold) && !isnan(a2->threshold)) {
+			if (!std::isnan(a1->threshold) && !std::isnan(a2->threshold)) {
 				return a1->threshold < a2->threshold;
 			}
 
-			if (isnan(a1->threshold) && isnan(a2->threshold)) {
+			if (std::isnan(a1->threshold) && std::isnan(a2->threshold)) {
 				return false;
 			}
-			else if (isnan(a1->threshold)) {
+			else if (std::isnan(a1->threshold)) {
 				return true;
 			}
 
@@ -1524,7 +1524,7 @@ rspamd_config_new_symbol(struct rspamd_c
 		rspamd_mempool_alloc0_type(cfg->cfg_pool, struct rspamd_symbol);
 	score_ptr = rspamd_mempool_alloc_type(cfg->cfg_pool, double);
 
-	if (isnan(score)) {
+	if (std::isnan(score)) {
 		/* In fact, it could be defined later */
 		msg_debug_config("score is not defined for symbol %s, set it to zero",
 						 symbol);
@@ -1635,7 +1635,7 @@ rspamd_config_add_symbol(struct rspamd_c
 		}
 
 		if (sym_def->priority > priority &&
-			(isnan(score) || !(sym_def->flags & RSPAMD_SYMBOL_FLAG_UNSCORED))) {
+			(std::isnan(score) || !(sym_def->flags & RSPAMD_SYMBOL_FLAG_UNSCORED))) {
 			msg_debug_config("symbol %s has been already registered with "
 							 "priority %ud, do not override (new priority: %ud)",
 							 symbol,
@@ -1656,7 +1656,7 @@ rspamd_config_add_symbol(struct rspamd_c
 		}
 		else {
 
-			if (!isnan(score)) {
+			if (!std::isnan(score)) {
 				msg_debug_config("symbol %s has been already registered with "
 								 "priority %ud, override it with new priority: %ud, "
 								 "old score: %.2f, new score: %.2f",
@@ -1996,7 +1996,7 @@ rspamd_config_action_from_ucl(struct rsp
 
 	/* TODO: add lua references support */
 
-	if (isnan(threshold) && !(flags & RSPAMD_ACTION_NO_THRESHOLD)) {
+	if (std::isnan(threshold) && !(flags & RSPAMD_ACTION_NO_THRESHOLD)) {
 		msg_err_config("action %s has no threshold being set and it is not"
 					   " a no threshold action",
 					   act->name);
