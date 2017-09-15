$NetBSD: patch-compile.c,v 1.2.2.2 2017/09/15 19:25:13 spz Exp $

This chanage included in r57971; moving declaration of new_opt to outside
of "if"'s block.  So, new_opt is still available outside of "if"'s block.

It cause problem when PKGSRC_USE_STACK_CHECK is enabled.

--- compile.c.orig	2017-02-07 17:39:54.000000000 +0000
+++ compile.c
@@ -5993,8 +5993,9 @@ iseq_compile_each(rb_iseq_t *iseq, LINK_
       }
       case NODE_PRELUDE:{
 	const rb_compile_option_t *orig_opt = ISEQ_COMPILE_DATA(iseq)->option;
+	rb_compile_option_t new_opt;
 	if (node->nd_orig) {
-	    rb_compile_option_t new_opt = *orig_opt;
+	    new_opt = *orig_opt;
 	    rb_iseq_make_compile_option(&new_opt, node->nd_orig);
 	    ISEQ_COMPILE_DATA(iseq)->option = &new_opt;
 	}
