$NetBSD: patch-src_lib_engines_common_evas__op__blend_op__blend__pixel__neon.c,v 1.1 2015/02/19 14:19:18 joerg Exp $

Match opening token. Use instruction gas produces, not what is written.

--- src/lib/engines/common/evas_op_blend/op_blend_pixel_neon.c.orig	2015-02-09 22:09:06.000000000 +0000
+++ src/lib/engines/common/evas_op_blend/op_blend_pixel_neon.c
@@ -76,7 +76,7 @@ _op_blend_p_dp_neon(DATA32 *s, DATA8 *m,
 		"cmp		%[tmp], #32		\n\t"
 		"blt		"AP"loopout		\n\t"
 
-		"vldm		%[s]!,	{d0,d1)		\n\t"
+		"vldm		%[s]!,	{d0,d1}		\n\t"
 		"vldm		%[d],	{d4,d5}		\n\t"
 
 
@@ -111,7 +111,7 @@ _op_blend_p_dp_neon(DATA32 *s, DATA8 *m,
 
 	AP "octloopint:\n\t"
 		//** Oct loop
-		"vldm	%[s]!,	{d0,d1,d2,d3)		\n\t"
+		"vldm	%[s]!,	{d0,d1,d2,d3}		\n\t"
 		"vldm	%[d],	{d4,d5,d6,d7}		\n\t"
                 "pld    [%[s], #64]                     \n\t"
                 
@@ -176,7 +176,7 @@ _op_blend_p_dp_neon(DATA32 *s, DATA8 *m,
 		// Add to 's'
 		"vqadd.u8	d4,	d8,d0		\n\t"
 
-		"vstr.32	d4,	[%[d]]		\n\t"
+		"vstr		d4,	[%[d]]		\n\t"
 		"add		%[d],   #8		\n\t"
 
 		"cmp 		%[tmp], %[d]		\n\t"
@@ -268,7 +268,7 @@ _op_blend_pas_dp_neon(DATA32 *s, DATA8 *
 
 	AP"dualloop:						\n\t"
 
-		"vldm	%[s]!,	{d0)				\n\t"
+		"vldm	%[s]!,	{d0}				\n\t"
 		"vldm	%[d],	{d4}				\n\t"
 
 		// Subtract from 255 (ie negate) and extract alpha channel
@@ -299,7 +299,7 @@ _op_blend_pas_dp_neon(DATA32 *s, DATA8 *
 		"sub		%[tmp], %[e],  #31		\n\t"
 
         AP"quadloop:\n\t"
-		"vldm	%[s]!,	{d0,d1,d2,d3)			\n\t"
+		"vldm	%[s]!,	{d0,d1,d2,d3}			\n\t"
 		"vldm	%[d],	{d4,d5,d6,d7}			\n\t"
 
 		// Subtract from 255 (ie negate) and extract alpha channel
@@ -350,7 +350,7 @@ _op_blend_pas_dp_neon(DATA32 *s, DATA8 *
 		"sub		%[tmp],%[e],$0x7		\n\t"
 
 	AP"dualloop2:						\n\t"
-		"vldm		%[s]!,	{d0)			\n\t"
+		"vldm		%[s]!,	{d0}			\n\t"
 		"vldm		%[d],	{d4}			\n\t"
 
 		// Subtract from 255 (ie negate) and extract alpha channel
