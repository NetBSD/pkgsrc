$NetBSD: patch-tests_test__config.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- tests/test_config.c.orig	2012-07-12 21:43:09.000000000 +0000
+++ tests/test_config.c
@@ -753,15 +753,19 @@ CONFIG_INFO_STANDARD(cfg_info, global_ob
 	.files = ACO_FILES(&config_test_conf),
 );
 
+RAII_DECL(struct test_config *, cfg, ao2_cleanup);
+RAII_DECL(struct test_item *, item, ao2_cleanup);
+RAII_DECL(struct test_item *, item_defaults, ao2_cleanup);
+
 AST_TEST_DEFINE(config_options_test)
 {
 	int res = AST_TEST_PASS, x, error;
 	struct test_item defaults = { 0, }, configs = { 0, };
 	struct test_item *arr[4];
 	struct ast_sockaddr acl_allow = {{ 0, }}, acl_fail = {{ 0, }};
-	RAII_VAR(struct test_config *, cfg, NULL, ao2_cleanup);
-	RAII_VAR(struct test_item *, item, NULL, ao2_cleanup);
-	RAII_VAR(struct test_item *, item_defaults, NULL, ao2_cleanup);
+	RAII_VAR(struct test_config *, cfg, NULL);
+	RAII_VAR(struct test_item *, item, NULL);
+	RAII_VAR(struct test_item *, item_defaults, NULL);
 
 	switch (cmd) {
 	case TEST_INIT:
