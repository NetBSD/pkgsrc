$NetBSD: patch-res_ael_pval.c,v 1.1 2016/07/23 08:27:44 jnemeth Exp $

--- res/ael/pval.c.orig	2016-07-21 14:56:56.000000000 +0000
+++ res/ael/pval.c
@@ -3344,6 +3344,9 @@ int contains_switch(pval *item)
 	return 0;
 }
 
+RAII_DECL(char *, buf1, free);
+RAII_DECL(char *, buf2, free);
+RAII_DECL(char *, new_label, free);
 
 static int gen_prios(struct ael_extension *exten, char *label, pval *statement, struct ael_extension *mother_exten, struct ast_context *this_context )
 {
@@ -3356,9 +3359,9 @@ static int gen_prios(struct ael_extensio
 #ifdef OLD_RAND_ACTION
 	struct ael_priority *rand_test, *rand_end, *rand_skip;
 #endif
-	RAII_VAR(char *, buf1, NULL, free);
-	RAII_VAR(char *, buf2, NULL, free);
-	RAII_VAR(char *, new_label, NULL, free);
+	RAII_VAR(char *, buf1, NULL);
+	RAII_VAR(char *, buf2, NULL);
+	RAII_VAR(char *, new_label, NULL);
 	char *strp, *strp2;
 	int default_exists;
 	int local_control_statement_count;
