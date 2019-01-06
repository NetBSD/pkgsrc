$NetBSD: patch-dbdimp.c,v 1.1 2019/01/06 09:09:16 markd Exp $

Fix SQL syntax for statements that have "...limit = ?"
commit 7805e828fad02d37f913228019cf352636fcfe36

--- dbdimp.c.orig	2018-11-17 18:49:08.000000000 +0000
+++ dbdimp.c
@@ -604,9 +604,9 @@ static char *parse_params(
       /*
         it would be good to be able to handle any number of cases and orders
       */
-      if ((*statement_ptr == 'l' || *statement_ptr == 'L') &&
-          (!strncmp(statement_ptr+1, "imit ", 5) ||
-           !strncmp(statement_ptr+1, "IMIT ", 5)))
+      if (((*statement_ptr == ' ') || (*statement_ptr == '\n') || (*statement_ptr == '\t')) &&
+          (!strncmp(statement_ptr+1, "limit ", 5) ||
+           !strncmp(statement_ptr+1, "LIMIT ", 5)))
       {
         limit_flag = 1;
       }
@@ -780,6 +780,7 @@ static char *parse_params(
 
 	/* in case this is a nested LIMIT */
       case ')':
+      case '=':
         limit_flag = 0;
 	*ptr++ = *statement_ptr++;
         break;
