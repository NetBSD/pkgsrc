$NetBSD: patch-main_test.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- main/test.c.orig	2014-06-19 19:34:37.000000000 +0000
+++ main/test.c
@@ -858,7 +858,7 @@ static char *test_cli_generate_results(s
 			if (!(buf = ast_str_create(256))) {
 				return NULL;
 			}
-			ast_str_set(&buf, 0, "%s/asterisk_test_results-%ld.%s", ast_config_AST_LOG_DIR, (long) time.tv_sec, type);
+			ast_str_set(&buf, 0, "%s/asterisk_test_results-%jd.%s", ast_config_AST_LOG_DIR, (intmax_t) time.tv_sec, type);
 
 			file = ast_str_buffer(buf);
 		}
