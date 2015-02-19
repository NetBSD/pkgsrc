$NetBSD: patch-src_lib_engines_common_evas__op__blend_op__blend__color__neon.c,v 1.1 2015/02/19 14:19:18 joerg Exp $

float vs double confusion, use what gas actually produces.

--- src/lib/engines/common/evas_op_blend/op_blend_color_neon.c.orig	2015-02-09 22:12:54.000000000 +0000
+++ src/lib/engines/common/evas_op_blend/op_blend_color_neon.c
@@ -46,7 +46,7 @@ _op_blend_c_dp_neon(DATA32 *s __UNUSED__
 
 
 	AP "dualloopint:					\n\t"
-		"vldr.32	d0, [%[d]]		\n\t"
+		"vldr		d0, [%[d]]		\n\t"
 		"vmull.u8	q1, d0, d14		\n\t"
 		"vqrshrn.u16	d0, q1, #8		\n\t"
 		"vqadd.u8	d0, d0, d12		\n\t"
