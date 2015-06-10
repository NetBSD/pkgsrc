$NetBSD: patch-main_loader.c,v 1.1.2.2 2015/06/10 20:38:43 tron Exp $

Fix unloaded module DSO usage

If a module once failed to load with globaly exposed symbols, the DSO
is unloaded while the struct ast_module remains valid and referenced, 
with just mod->lib being NULL.

If the module is later attempted to be loaded again, make sure the DSO
is loaded again to avoid an unpleasant crash.

Also add a test to catch the situation where something went wrong and 
loading failed again.

Submitted upstream in
https://issues.asterisk.org/jira/browse/ASTERISK-25021

--- main/loader.c.orig	2015-04-27 17:33:30.000000000 +0200
+++ main/loader.c	2015-04-27 18:01:28.000000000 +0200
@@ -894,9 +894,9 @@
 {
 	struct ast_module *mod;
 	enum ast_module_load_result res = AST_MODULE_LOAD_SUCCESS;
 
-	if ((mod = find_resource(resource_name, 0))) {
+	if ((mod = find_resource(resource_name, 0)) && (mod->lib != NULL)) {
 		if (mod->flags.running) {
 			ast_log(LOG_WARNING, "Module '%s' already exists.\n", resource_name);
 			return AST_MODULE_LOAD_DECLINE;
 		}
@@ -918,8 +918,14 @@
 		return required ? AST_MODULE_LOAD_FAILURE : AST_MODULE_LOAD_DECLINE;
 #endif
 	}
 
+	if (mod->lib == NULL) {
+		ast_log(LOG_ERROR, "Module '%s' was unloaded.\n", resource_name);
+		return required ? AST_MODULE_LOAD_FAILURE : AST_MODULE_LOAD_DECLINE;
+	}
+
+
 	if (inspect_module(mod)) {
 		ast_log(LOG_WARNING, "Module '%s' could not be loaded.\n", resource_name);
 #ifdef LOADABLE_MODULES
 		unload_dynamic_module(mod);
