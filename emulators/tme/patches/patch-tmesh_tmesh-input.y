$NetBSD: patch-tmesh_tmesh-input.y,v 1.1 2013/02/26 23:39:18 joerg Exp $

--- tmesh/tmesh-input.y.orig	2013-02-26 21:54:57.000000000 +0000
+++ tmesh/tmesh-input.y
@@ -301,7 +301,7 @@ _tmesh_parser_argv_arg(struct tmesh_pars
 static void
 yyerror(char *msg)
 {
-  tme_output_append(_tmesh_output, msg);
+  tme_output_append(_tmesh_output, "%s", msg);
   _tmesh_input->tmesh_scanner.tmesh_scanner_in_args = FALSE;
 }
 
