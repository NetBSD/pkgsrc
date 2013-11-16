$NetBSD: patch-gcc_config_nios2_nios2.c,v 1.1 2013/11/16 07:41:00 mef Exp $

Move prototype to nios2-proto.h, thanks nisimura@

diff --git a/gcc-4.1/gcc/config/nios2/nios2.c b/gcc-4.1/gcc/config/nios2/nios2.c
index f8cdb9d..fafa968 100644
--- a/gcc-4.1/gcc/config/nios2/nios2.c
+++ gcc/config/nios2/nios2.c
@@ -84,10 +84,8 @@ static tree nios2_handle_struct_attribute (tree *, tree, tree, int, bool *);
 static void nios2_insert_attributes (tree, tree *);
 static void nios2_load_pic_register (void);
 static bool nios2_cannot_force_const_mem (rtx);
-bool nios2_legitimate_pic_operand_p (rtx x);
 static rtx nios2_legitimize_pic_address (rtx orig, enum machine_mode mode,
 					 rtx reg);
-rtx nios2_legitimize_address (rtx x, rtx orig_x, enum machine_mode mode);
 static void nios2_init_builtins (void);
 static rtx nios2_expand_builtin (tree, rtx, rtx, enum machine_mode, int);
 static bool nios2_function_ok_for_sibcall (tree, tree);
@@ -2361,7 +2359,7 @@ nios2_legitimate_constant (rtx x)
     }
 }
 
-int
+bool
 nios2_legitimate_address (rtx operand, enum machine_mode mode ATTRIBUTE_UNUSED,
                           int strict)
 {
