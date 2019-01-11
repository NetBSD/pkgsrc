$NetBSD: patch-libgnucash_app-utils_calculation_expression__parser.c,v 1.2 2019/01/11 12:01:11 wiz Exp $

is* takes a char argument.
https://bugs.gnucash.org/show_bug.cgi?id=797039

--- libgnucash/app-utils/calculation/expression_parser.c.orig	2018-12-25 22:43:08.000000000 +0000
+++ libgnucash/app-utils/calculation/expression_parser.c
@@ -768,7 +768,7 @@ next_token (parser_env_ptr pe)
     const char *str_parse = pe->parse_str;
     void *number;
 
-    while (isspace (*str_parse))
+    while (isspace ((unsigned char)*str_parse))
         str_parse++;
 
     pe->asn_op = EOS;
@@ -812,7 +812,7 @@ next_token (parser_env_ptr pe)
         add_token( pe, STR_TOKEN );
     }
     /* test for name */
-    else if (isalpha (*str_parse)
+    else if (isalpha ((unsigned char)*str_parse)
              || (*str_parse == '_'))
     {
         int funcFlag = 0;
@@ -833,8 +833,8 @@ next_token (parser_env_ptr pe)
         }
         while ((*str_parse == '_')
                 || (*str_parse == '(')
-                || isalpha (*str_parse)
-                || isdigit (*str_parse));
+                || isalpha ((unsigned char)*str_parse)
+                || isdigit ((unsigned char)*str_parse));
 
         *nstr = EOS;
         if ( funcFlag )
