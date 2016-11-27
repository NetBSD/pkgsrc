$NetBSD: patch-__KDE__build_src_solid_predicate__lexer.c,v 1.1 2016/11/27 22:56:17 kamil Exp $

Fix: error: C++ style comments are not allowed in ISO C90

--- _KDE_build/src/solid/predicate_lexer.c.orig	2016-11-27 22:27:30.788034675 +0000
+++ _KDE_build/src/solid/predicate_lexer.c
@@ -1589,7 +1589,7 @@ static void Solidensure_buffer_stack (yy
 		 * scanner will even need a stack. We use 2 instead of 1 to avoid an
 		 * immediate realloc on the next call.
          */
-		num_to_alloc = 1; // After all that talk, this was set to 1 anyways...
+		num_to_alloc = 1; /* After all that talk, this was set to 1 anyways... */
 		yyg->yy_buffer_stack = (struct yy_buffer_state**)Solidalloc
 								(num_to_alloc * sizeof(struct yy_buffer_state*)
 								, yyscanner);
@@ -2140,5 +2140,3 @@ int Solidwrap( yyscan_t _scanner )
     Solid_delete_buffer( YY_CURRENT_BUFFER, _scanner );
     return 1;
 }
-
-
