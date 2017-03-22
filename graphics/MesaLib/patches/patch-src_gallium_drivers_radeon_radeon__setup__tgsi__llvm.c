$NetBSD: patch-src_gallium_drivers_radeon_radeon__setup__tgsi__llvm.c,v 1.1 2017/03/22 20:22:31 markd Exp $

--- src/gallium/drivers/radeon/radeon_setup_tgsi_llvm.c.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/gallium/drivers/radeon/radeon_setup_tgsi_llvm.c
@@ -773,14 +773,14 @@ static void radeon_llvm_cube_to_2d_coord
 
 	cube_vec = lp_build_gather_values(bld_base->base.gallivm, in, 4);
 	v = lp_build_intrinsic(builder, "llvm.AMDGPU.cube", LLVMVectorType(type, 4),
-                            &cube_vec, 1, LLVMReadNoneAttribute);
+                            &cube_vec, 1, LP_FUNC_ATTR_READNONE);
 
 	for (i = 0; i < 4; ++i)
 		coords[i] = LLVMBuildExtractElement(builder, v,
 						    lp_build_const_int32(gallivm, i), "");
 
 	coords[2] = lp_build_intrinsic(builder, "llvm.fabs.f32",
-			type, &coords[2], 1, LLVMReadNoneAttribute);
+			type, &coords[2], 1, LP_FUNC_ATTR_READNONE);
 	coords[2] = lp_build_emit_llvm_unary(bld_base, TGSI_OPCODE_RCP, coords[2]);
 
 	mad_args[1] = coords[2];
@@ -1215,7 +1215,7 @@ static void emit_frac(
 
 	LLVMValueRef floor = lp_build_intrinsic(builder, intr, emit_data->dst_type,
 						&emit_data->args[0], 1,
-						LLVMReadNoneAttribute);
+						LP_FUNC_ATTR_READNONE);
 	emit_data->output[emit_data->chan] = LLVMBuildFSub(builder,
 			emit_data->args[0], floor, "");
 }
@@ -1283,7 +1283,7 @@ build_tgsi_intrinsic_nomem(const struct 
 	emit_data->output[emit_data->chan] =
 		lp_build_intrinsic(base->gallivm->builder, action->intr_name,
 				   emit_data->dst_type, emit_data->args,
-				   emit_data->arg_count, LLVMReadNoneAttribute);
+				   emit_data->arg_count, LP_FUNC_ATTR_READNONE);
 }
 
 static void emit_bfi(const struct lp_build_tgsi_action * action,
@@ -1341,7 +1341,7 @@ static void emit_lsb(const struct lp_bui
 	emit_data->output[emit_data->chan] =
 		lp_build_intrinsic(gallivm->builder, "llvm.cttz.i32",
 				emit_data->dst_type, args, Elements(args),
-				LLVMReadNoneAttribute);
+				LP_FUNC_ATTR_READNONE);
 }
 
 /* Find the last bit set. */
@@ -1360,7 +1360,7 @@ static void emit_umsb(const struct lp_bu
 	LLVMValueRef msb =
 		lp_build_intrinsic(builder, "llvm.ctlz.i32",
 				emit_data->dst_type, args, Elements(args),
-				LLVMReadNoneAttribute);
+				LP_FUNC_ATTR_READNONE);
 
 	/* The HW returns the last bit index from MSB, but TGSI wants
 	 * the index from LSB. Invert it by doing "31 - msb". */
@@ -1387,7 +1387,7 @@ static void emit_imsb(const struct lp_bu
 	LLVMValueRef msb =
 		lp_build_intrinsic(builder, "llvm.AMDGPU.flbit.i32",
 				emit_data->dst_type, &arg, 1,
-				LLVMReadNoneAttribute);
+				LP_FUNC_ATTR_READNONE);
 
 	/* The HW returns the last bit index from MSB, but TGSI wants
 	 * the index from LSB. Invert it by doing "31 - msb". */
