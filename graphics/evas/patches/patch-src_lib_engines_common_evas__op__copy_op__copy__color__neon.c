$NetBSD: patch-src_lib_engines_common_evas__op__copy_op__copy__color__neon.c,v 1.1 2015/02/19 14:19:18 joerg Exp $

float vs double confusion, use what gas actually produces.

--- src/lib/engines/common/evas_op_copy/op_copy_color_neon.c.orig	2015-02-09 22:11:34.000000000 +0000
+++ src/lib/engines/common/evas_op_copy/op_copy_color_neon.c
@@ -30,7 +30,7 @@ _op_copy_c_dp_neon(DATA32 *s, DATA8 *m, 
 		"blt		"AP"loopout		\n\t"
 
 	AP"dualloop:					\n\t"
-		"vstr.32	d0, [%[d]]		\n\t"
+		"vstr		d0, [%[d]]		\n\t"
 
 		"add		%[d], #8		\n\t"
 		"andS		%[tmp], %[d], $0x1f	\n\t"
