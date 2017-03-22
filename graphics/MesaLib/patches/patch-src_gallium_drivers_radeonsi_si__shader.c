$NetBSD: patch-src_gallium_drivers_radeonsi_si__shader.c,v 1.1 2017/03/22 20:22:31 markd Exp $

llvm api change
commit  8bdd52c8f3595128cbc1da4f23cdb10ff861a6ef

--- src/gallium/drivers/radeonsi/si_shader.c.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_shader.c
@@ -472,7 +472,7 @@ static void declare_input_vs(
 	args[2] = buffer_index;
 	input = lp_build_intrinsic(gallivm->builder,
 		"llvm.SI.vs.load.input", ctx->v4f32, args, 3,
-		LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+		LP_FUNC_ATTR_READNONE);
 
 	/* Break up the vec4 into individual components */
 	for (chan = 0; chan < 4; chan++) {
@@ -834,14 +834,14 @@ static LLVMValueRef fetch_input_gs(
 	value = lp_build_intrinsic(gallivm->builder,
 				   "llvm.SI.buffer.load.dword.i32.i32",
 				   ctx->i32, args, 9,
-				   LLVMReadOnlyAttribute | LLVMNoUnwindAttribute);
+				   LP_FUNC_ATTR_READONLY);
 	if (type == TGSI_TYPE_DOUBLE) {
 		LLVMValueRef value2;
 		args[2] = lp_build_const_int32(gallivm, (param * 4 + swizzle + 1) * 256);
 		value2 = lp_build_intrinsic(gallivm->builder,
 					    "llvm.SI.buffer.load.dword.i32.i32",
 					    ctx->i32, args, 9,
-					    LLVMReadOnlyAttribute | LLVMNoUnwindAttribute);
+					    LP_FUNC_ATTR_READONLY);
 		return radeon_llvm_emit_fetch_double(bld_base,
 						     value, value2);
 	}
@@ -981,12 +981,12 @@ static void interp_fs_input(struct si_sh
 			args[1] = attr_number;
 			front = lp_build_intrinsic(gallivm->builder, intr_name,
 						ctx->f32, args, args[3] ? 4 : 3,
-						LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+						LP_FUNC_ATTR_READNONE);
 
 			args[1] = back_attr_number;
 			back = lp_build_intrinsic(gallivm->builder, intr_name,
 					       ctx->f32, args, args[3] ? 4 : 3,
-					       LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+					       LP_FUNC_ATTR_READNONE);
 
 			result[chan] = LLVMBuildSelect(gallivm->builder,
 						is_face_positive,
@@ -1003,7 +1003,7 @@ static void interp_fs_input(struct si_sh
 		args[3] = interp_param;
 		result[0] = lp_build_intrinsic(gallivm->builder, intr_name,
 					ctx->f32, args, args[3] ? 4 : 3,
-					LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+					LP_FUNC_ATTR_READNONE);
 		result[1] =
 		result[2] = lp_build_const_float(gallivm, 0.0f);
 		result[3] = lp_build_const_float(gallivm, 1.0f);
@@ -1018,7 +1018,7 @@ static void interp_fs_input(struct si_sh
 			args[3] = interp_param;
 			result[chan] = lp_build_intrinsic(gallivm->builder, intr_name,
 						ctx->f32, args, args[3] ? 4 : 3,
-						LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+						LP_FUNC_ATTR_READNONE);
 		}
 	}
 }
@@ -1089,7 +1089,7 @@ static LLVMValueRef buffer_load_const(LL
 	LLVMValueRef args[2] = {resource, offset};
 
 	return lp_build_intrinsic(builder, "llvm.SI.load.const", return_type, args, 2,
-			       LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+			       LP_FUNC_ATTR_READNONE);
 }
 
 static LLVMValueRef load_sample_position(struct radeon_llvm_context *radeon_bld, LLVMValueRef sample_id)
@@ -1432,7 +1432,7 @@ static void si_llvm_init_export_args(str
 			packed = lp_build_intrinsic(base->gallivm->builder,
 						    "llvm.SI.packf16",
 						    ctx->i32, pack_args, 2,
-						    LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+						    LP_FUNC_ATTR_READNONE);
 			args[chan + 5] =
 				LLVMBuildBitCast(base->gallivm->builder,
 						 packed, ctx->f32, "");
@@ -1577,7 +1577,7 @@ static LLVMValueRef si_scale_alpha_by_sa
 
 	coverage = lp_build_intrinsic(gallivm->builder, "llvm.ctpop.i32",
 				   ctx->i32,
-				   &coverage, 1, LLVMReadNoneAttribute);
+				   &coverage, 1, LP_FUNC_ATTR_READNONE);
 
 	coverage = LLVMBuildUIToFP(gallivm->builder, coverage,
 				   ctx->f32, "");
@@ -1742,7 +1742,7 @@ static void si_llvm_emit_streamout(struc
 		unpack_param(ctx, ctx->param_streamout_config, 16, 7);
 
 	LLVMValueRef tid = lp_build_intrinsic(builder, "llvm.SI.tid", ctx->i32,
-					   NULL, 0, LLVMReadNoneAttribute);
+					   NULL, 0, LP_FUNC_ATTR_READNONE);
 
 	/* can_emit = tid < so_vtx_count; */
 	LLVMValueRef can_emit =
@@ -2242,7 +2242,7 @@ static void si_llvm_emit_gs_epilogue(str
 	args[0] = lp_build_const_int32(gallivm,	SENDMSG_GS_OP_NOP | SENDMSG_GS_DONE);
 	args[1] = LLVMGetParam(ctx->radeon_bld.main_fn, SI_PARAM_GS_WAVE_ID);
 	lp_build_intrinsic(gallivm->builder, "llvm.SI.sendmsg",
-			   ctx->voidt, args, 2, LLVMNoUnwindAttribute);
+			   ctx->voidt, args, 2, LP_FUNC_ATTR_NOUNWIND);
 }
 
 static void si_llvm_emit_vs_epilogue(struct lp_build_tgsi_context *bld_base)
@@ -3191,7 +3191,7 @@ static void build_tex_intrinsic(const st
 			base->gallivm->builder,
 			"llvm.SI.vs.load.input", emit_data->dst_type,
 			emit_data->args, emit_data->arg_count,
-			LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+			LP_FUNC_ATTR_READNONE);
 		return;
 	}
 
@@ -3251,7 +3251,7 @@ static void build_tex_intrinsic(const st
 	emit_data->output[emit_data->chan] = lp_build_intrinsic(
 		base->gallivm->builder, intr_name, emit_data->dst_type,
 		emit_data->args, emit_data->arg_count,
-		LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+		LP_FUNC_ATTR_READNONE);
 
 	/* Divide the number of layers by 6 to get the number of cubes. */
 	if (opcode == TGSI_OPCODE_TXQ &&
@@ -3347,7 +3347,7 @@ static void si_llvm_emit_ddxy(
 
 	indices[0] = bld_base->uint_bld.zero;
 	indices[1] = lp_build_intrinsic(gallivm->builder, "llvm.SI.tid", ctx->i32,
-				     NULL, 0, LLVMReadNoneAttribute);
+				     NULL, 0, LP_FUNC_ATTR_READNONE);
 	store_ptr = LLVMBuildGEP(gallivm->builder, ctx->lds,
 				 indices, 2, "");
 
@@ -3419,7 +3419,7 @@ static LLVMValueRef si_llvm_emit_ddxy_in
 
 	indices[0] = bld_base->uint_bld.zero;
 	indices[1] = lp_build_intrinsic(gallivm->builder, "llvm.SI.tid", ctx->i32,
-					NULL, 0, LLVMReadNoneAttribute);
+					NULL, 0, LP_FUNC_ATTR_READNONE);
 	store_ptr = LLVMBuildGEP(gallivm->builder, ctx->lds,
 				 indices, 2, "");
 
@@ -3616,7 +3616,7 @@ static void build_interp_intrinsic(const
 		emit_data->output[chan] =
 			lp_build_intrinsic(gallivm->builder, intr_name,
 					   ctx->f32, args, args[3] ? 4 : 3,
-					   LLVMReadNoneAttribute | LLVMNoUnwindAttribute);
+					   LP_FUNC_ATTR_READNONE);
 	}
 }
 
@@ -3708,7 +3708,7 @@ static void si_llvm_emit_vertex(
 	args[0] = lp_build_const_int32(gallivm, SENDMSG_GS_OP_EMIT | SENDMSG_GS | (stream << 8));
 	args[1] = LLVMGetParam(ctx->radeon_bld.main_fn, SI_PARAM_GS_WAVE_ID);
 	lp_build_intrinsic(gallivm->builder, "llvm.SI.sendmsg",
-			   ctx->voidt, args, 2, LLVMNoUnwindAttribute);
+			   ctx->voidt, args, 2, LP_FUNC_ATTR_NOUNWIND);
 }
 
 /* Cut one primitive from the geometry shader */
@@ -3727,7 +3727,7 @@ static void si_llvm_emit_primitive(
 	args[0] = lp_build_const_int32(gallivm,	SENDMSG_GS_OP_CUT | SENDMSG_GS | (stream << 8));
 	args[1] = LLVMGetParam(ctx->radeon_bld.main_fn, SI_PARAM_GS_WAVE_ID);
 	lp_build_intrinsic(gallivm->builder, "llvm.SI.sendmsg",
-			   ctx->voidt, args, 2, LLVMNoUnwindAttribute);
+			   ctx->voidt, args, 2, LP_FUNC_ATTR_NOUNWIND);
 }
 
 static void si_llvm_emit_barrier(const struct lp_build_tgsi_action *action,
@@ -3740,7 +3740,7 @@ static void si_llvm_emit_barrier(const s
 	lp_build_intrinsic(gallivm->builder,
 			   HAVE_LLVM >= 0x0309 ? "llvm.amdgcn.s.barrier"
 					       : "llvm.AMDGPU.barrier.local",
-			   ctx->voidt, NULL, 0, LLVMNoUnwindAttribute);
+			   ctx->voidt, NULL, 0, LP_FUNC_ATTR_NOUNWIND);
 }
 
 static const struct lp_build_tgsi_action tex_action = {
@@ -3771,9 +3771,9 @@ static void si_create_function(struct si
 		/* We tell llvm that array inputs are passed by value to allow Sinking pass
 		 * to move load. Inputs are constant so this is fine. */
 		if (i <= last_array_pointer)
-			LLVMAddAttribute(P, LLVMByValAttribute);
+			lp_add_function_attr(ctx->radeon_bld.main_fn, i + 1, LP_FUNC_ATTR_BYVAL);
 		else
-			LLVMAddAttribute(P, LLVMInRegAttribute);
+			lp_add_function_attr(ctx->radeon_bld.main_fn, i + 1, LP_FUNC_ATTR_INREG);
 	}
 }
 
@@ -4699,7 +4699,7 @@ static int si_generate_gs_copy_shader(st
 						 lp_build_intrinsic(gallivm->builder,
 								 "llvm.SI.buffer.load.dword.i32.i32",
 								 ctx->i32, args, 9,
-								 LLVMReadOnlyAttribute | LLVMNoUnwindAttribute),
+								 LP_FUNC_ATTR_READONLY),
 						 ctx->f32, "");
 		}
 	}
