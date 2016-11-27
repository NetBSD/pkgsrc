$NetBSD: patch-__KDE__build_src_lex.c,v 1.1 2016/11/27 22:17:22 kamil Exp $

Fix: error: C++ style comments are not allowed in ISO C90

--- _KDE_build/src/lex.c.orig	2016-11-27 22:10:29.983786387 +0000
+++ _KDE_build/src/lex.c
@@ -1710,7 +1710,7 @@ static void kiotraderensure_buffer_stack
 		 * scanner will even need a stack. We use 2 instead of 1 to avoid an
 		 * immediate realloc on the next call.
          */
-		num_to_alloc = 1; // After all that talk, this was set to 1 anyways...
+		num_to_alloc = 1; /* After all that talk, this was set to 1 anyways... */
 		yyg->yy_buffer_stack = (struct yy_buffer_state**)kiotraderalloc
 								(num_to_alloc * sizeof(struct yy_buffer_state*)
 								, yyscanner);
@@ -2303,4 +2303,3 @@ int kiotraderwrap(yyscan_t _scanner )
   kiotrader_delete_buffer(YY_CURRENT_BUFFER,_scanner );
   return 1;
 }
-
