$NetBSD: patch-Zend_zend_language_parser.h,v 1.2.2.2 2014/08/18 12:48:05 tron Exp $

https://bugs.php.net/bug.php?id=64503

--- Zend/zend_language_parser.h.orig	2013-12-10 20:13:14.000000000 +0000
+++ Zend/zend_language_parser.h
@@ -305,6 +305,10 @@ typedef int YYSTYPE;
 # define YYSTYPE_IS_DECLARED 1
 #endif
 
+#ifdef ZTS
+# define YYPARSE_PARAM tsrm_ls
+# define YYLEX_PARAM tsrm_ls
+#endif
 
 #ifdef YYPARSE_PARAM
 #if defined __STDC__ || defined __cplusplus
