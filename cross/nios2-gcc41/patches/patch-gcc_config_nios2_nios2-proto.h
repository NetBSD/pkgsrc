$NetBSD: patch-gcc_config_nios2_nios2-proto.h,v 1.1 2013/11/16 07:41:00 mef Exp $

Correction of prototype declaration.
This was origin of segmentation fault at compiling crtstuff.c
on 64bit machine, thanks nisimura@

diff --git a/gcc-4.1/gcc/config/nios2/nios2-protos.h b/gcc-4.1/gcc/config/nios2/nios2-protos.h
index 7f72eaa..2b7db5d 100644
--- a/gcc-4.1/gcc/config/nios2/nios2-protos.h
+++ gcc/config/nios2/nios2-protos.h
@@ -35,8 +35,10 @@ extern enum reg_class reg_class_from_constraint (char, const char *);
 extern void nios2_register_target_pragmas (void);
 
 #ifdef RTX_CODE
-extern int nios2_legitimate_address (rtx, enum machine_mode, int);
+extern bool nios2_legitimate_pic_operand_p (rtx x);
+extern bool nios2_legitimate_address (rtx, enum machine_mode, int);
 extern int nios2_legitimate_constant (rtx);
+extern rtx nios2_legitimize_address (rtx, rtx, enum machine_mode);
 extern void nios2_print_operand (FILE *, rtx, int);
 extern void nios2_print_operand_address (FILE *, rtx);
 
