$NetBSD: patch-tmesh_tmesh-input.y,v 1.2 2013/11/02 21:53:36 martin Exp $

Add missing format string parameter and avoid a crash on EOF on the shells
input.

--- tmesh/tmesh-input.y.orig	2006-11-16 00:11:31.000000000 +0100
+++ tmesh/tmesh-input.y	2013-11-02 22:45:05.000000000 +0100
@@ -301,7 +301,7 @@
 static void
 yyerror(char *msg)
 {
-  tme_output_append(_tmesh_output, msg);
+  tme_output_append(_tmesh_output, "%s", msg);
   _tmesh_input->tmesh_scanner.tmesh_scanner_in_args = FALSE;
 }
 
@@ -468,6 +468,9 @@
       scanner->tmesh_scanner_in_quotes = FALSE;
       scanner->tmesh_scanner_in_comment = FALSE;
 
+      if (stack->tmesh_io_stack_next == NULL)
+        _exit(0);
+
       /* close the now-finished source: */
       (*source->tmesh_io_close)(source, 
 				(stack->tmesh_io_stack_next != NULL
