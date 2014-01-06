$NetBSD: patch-gas_config_tc-i386.c,v 1.1 2014/01/06 14:58:41 wiz Exp $

Comment out unused variables (-Wno-unused complains about them,
and with -Werror build fails).

--- gas/config/tc-i386.c.orig	2013-11-26 11:37:33.000000000 +0000
+++ gas/config/tc-i386.c
@@ -1665,8 +1665,8 @@ static const i386_operand_type imm16_32 
 static const i386_operand_type imm16_32s = OPERAND_TYPE_IMM16_32S;
 static const i386_operand_type imm16_32_32s = OPERAND_TYPE_IMM16_32_32S;
 static const i386_operand_type vec_imm4 = OPERAND_TYPE_VEC_IMM4;
-static const i386_operand_type regbnd = OPERAND_TYPE_REGBND;
-static const i386_operand_type vec_disp8 = OPERAND_TYPE_VEC_DISP8;
+//static const i386_operand_type regbnd = OPERAND_TYPE_REGBND;
+//static const i386_operand_type vec_disp8 = OPERAND_TYPE_VEC_DISP8;
 
 enum operand_type
 {
