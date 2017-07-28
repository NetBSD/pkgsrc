$NetBSD: patch-gcc_config_i386_i386.c,v 1.3 2017/07/28 23:40:07 maya Exp $

Incorrect codegen from rdseed intrinsic use (CVE-2017-11671)

We should not expand call arguments in between flags reg setting and
flags reg using instructions, as it may expand with flags reg
clobbering insn (ADD in this case).

Attached patch moves expansion out of the link. Also, change
zero-extension to non-flags reg clobbering sequence in case we perform
zero-extension with and.

2017-03-25  Uros Bizjak

--- gcc/config/i386/i386.c.orig	2015-06-10 09:34:21.000000000 +0000
+++ gcc/config/i386/i386.c
@@ -32099,9 +32099,6 @@ ix86_expand_builtin (tree exp, rtx targe
       mode0 = DImode;
 
 rdrand_step:
-      op0 = gen_reg_rtx (mode0);
-      emit_insn (GEN_FCN (icode) (op0));
-
       arg0 = CALL_EXPR_ARG (exp, 0);
       op1 = expand_normal (arg0);
       if (!address_operand (op1, VOIDmode))
@@ -32109,6 +32106,10 @@ rdrand_step:
 	  op1 = convert_memory_address (Pmode, op1);
 	  op1 = copy_addr_to_reg (op1);
 	}
+
+      op0 = gen_reg_rtx (mode0);
+      emit_insn (GEN_FCN (icode) (op0));
+
       emit_move_insn (gen_rtx_MEM (mode0, op1), op0);
 
       op1 = gen_reg_rtx (SImode);
@@ -32117,8 +32118,20 @@ rdrand_step:
       /* Emit SImode conditional move.  */
       if (mode0 == HImode)
 	{
-	  op2 = gen_reg_rtx (SImode);
-	  emit_insn (gen_zero_extendhisi2 (op2, op0));
+	  if (TARGET_ZERO_EXTEND_WITH_AND
+	      && optimize_function_for_speed_p (cfun))
+	    {
+	      op2 = force_reg (SImode, const0_rtx);
+
+	      emit_insn (gen_movstricthi
+			 (gen_lowpart (HImode, op2), op0));
+	    }
+	  else
+	    {
+	      op2 = gen_reg_rtx (SImode);
+
+	      emit_insn (gen_zero_extendhisi2 (op2, op0));
+	    }
 	}
       else if (mode0 == SImode)
 	op2 = op0;
@@ -32150,9 +32163,6 @@ rdrand_step:
       mode0 = DImode;
 
 rdseed_step:
-      op0 = gen_reg_rtx (mode0);
-      emit_insn (GEN_FCN (icode) (op0));
-
       arg0 = CALL_EXPR_ARG (exp, 0);
       op1 = expand_normal (arg0);
       if (!address_operand (op1, VOIDmode))
@@ -32160,6 +32170,10 @@ rdseed_step:
 	  op1 = convert_memory_address (Pmode, op1);
 	  op1 = copy_addr_to_reg (op1);
 	}
+
+      op0 = gen_reg_rtx (mode0);
+      emit_insn (GEN_FCN (icode) (op0));
+
       emit_move_insn (gen_rtx_MEM (mode0, op1), op0);
 
       op2 = gen_reg_rtx (QImode);
