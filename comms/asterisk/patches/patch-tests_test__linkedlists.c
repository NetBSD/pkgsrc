$NetBSD: patch-tests_test__linkedlists.c,v 1.1 2014/07/02 03:06:24 jnemeth Exp $

--- tests/test_linkedlists.c.orig	2013-10-24 19:55:23.000000000 +0000
+++ tests/test_linkedlists.c
@@ -124,9 +124,11 @@ static int dbl_list_expect_reverse(struc
 		return AST_TEST_FAIL; \
 	}
 
+RAII_VAR(struct ast_str *, buf, ast_free);
+
 AST_TEST_DEFINE(single_ll_tests)
 {
-	RAII_VAR(struct ast_str *, buf, NULL, ast_free);
+	RAII_VAR(struct ast_str *, buf, NULL);
 	struct test_llist test_list = { 0, };
 	struct test_llist other_list = { 0, };
 	struct test_val *bogus;
@@ -337,7 +339,7 @@ AST_TEST_DEFINE(single_ll_tests)
 
 AST_TEST_DEFINE(double_ll_tests)
 {
-	RAII_VAR(struct ast_str *, buf, NULL, ast_free);
+	RAII_VAR(struct ast_str *, buf, NULL);
 	struct test_dbl_llist test_list = { 0, };
 	struct test_dbl_llist other_list = { 0, };
 	struct test_val *bogus;
