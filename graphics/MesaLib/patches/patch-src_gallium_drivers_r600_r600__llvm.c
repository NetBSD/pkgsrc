$NetBSD: patch-src_gallium_drivers_r600_r600__llvm.c,v 1.1 2017/03/22 20:22:31 markd Exp $

--- src/gallium/drivers/r600/r600_llvm.c.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/gallium/drivers/r600/r600_llvm.c
@@ -101,9 +101,9 @@ llvm_load_input_vector(
 				lp_build_const_int32(&(ctx->gallivm), 2 * (ijregs % 2) + 1), "");
 			LLVMValueRef HalfVec[2] = {
 				lp_build_intrinsic(ctx->gallivm.builder, "llvm.R600.interp.xy",
-					VecType, Args, ArgCount, LLVMReadNoneAttribute),
+					VecType, Args, ArgCount, LP_FUNC_ATTR_READNONE),
 				lp_build_intrinsic(ctx->gallivm.builder, "llvm.R600.interp.zw",
-					VecType, Args, ArgCount, LLVMReadNoneAttribute)
+					VecType, Args, ArgCount, LP_FUNC_ATTR_READNONE)
 			};
 			LLVMValueRef MaskInputs[4] = {
 				lp_build_const_int32(&(ctx->gallivm), 0),
@@ -117,7 +117,7 @@ llvm_load_input_vector(
 		} else {
 			VecType = LLVMVectorType(ctx->soa.bld_base.base.elem_type, 4);
 			return lp_build_intrinsic(ctx->gallivm.builder, "llvm.R600.interp.const",
-				VecType, Args, ArgCount, LLVMReadNoneAttribute);
+				VecType, Args, ArgCount, LP_FUNC_ATTR_READNONE);
 		}
 }
 
@@ -273,7 +273,7 @@ static void llvm_emit_epilogue(struct lp
 						args[1] = base_vector;
 						adjusted_elements[chan] = lp_build_intrinsic(base->gallivm->builder,
 							"llvm.AMDGPU.dp4", bld_base->base.elem_type,
-							args, 2, LLVMReadNoneAttribute);
+							args, 2, LP_FUNC_ATTR_READNONE);
 					}
 					args[0] = lp_build_gather_values(base->gallivm,
 						adjusted_elements, 4);
@@ -443,7 +443,7 @@ static void llvm_emit_tex(
 			args[1] = lp_build_const_int32(gallivm, R600_MAX_CONST_BUFFERS);
 			emit_data->output[0] = lp_build_intrinsic(gallivm->builder,
 							"llvm.R600.load.texbuf",
-							emit_data->dst_type, args, 2, LLVMReadNoneAttribute);
+							emit_data->dst_type, args, 2, LP_FUNC_ATTR_READNONE);
 			if (ctx->chip_class >= EVERGREEN)
 				return;
 			ctx->uses_tex_buffers = true;
@@ -558,7 +558,7 @@ static void llvm_emit_tex(
 			};
 			LLVMValueRef ptr = lp_build_intrinsic(gallivm->builder,
 				"llvm.R600.ldptr",
-				emit_data->dst_type, ldptr_args, 10, LLVMReadNoneAttribute);
+				emit_data->dst_type, ldptr_args, 10, LP_FUNC_ATTR_READNONE);
 			LLVMValueRef Tmp = LLVMBuildExtractElement(gallivm->builder, args[0],
 				lp_build_const_int32(gallivm, 3), "");
 			Tmp = LLVMBuildMul(gallivm->builder, Tmp,
@@ -579,7 +579,7 @@ static void llvm_emit_tex(
 
 	emit_data->output[0] = lp_build_intrinsic(gallivm->builder,
 					action->intr_name,
-					emit_data->dst_type, args, c, LLVMReadNoneAttribute);
+					emit_data->dst_type, args, c, LP_FUNC_ATTR_READNONE);
 
 	if (emit_data->inst->Instruction.Opcode == TGSI_OPCODE_TXQ &&
 		((emit_data->inst->Texture.Texture == TGSI_TEXTURE_CUBE_ARRAY ||
@@ -791,8 +791,7 @@ LLVMModuleRef r600_tgsi_llvm(
 		Arguments[ArgumentsCount++] = LLVMVectorType(bld_base->base.elem_type, 4);
 	radeon_llvm_create_func(ctx, NULL, 0, Arguments, ArgumentsCount);
 	for (unsigned i = 0; i < ctx->inputs_count; i++) {
-		LLVMValueRef P = LLVMGetParam(ctx->main_fn, i);
-		LLVMAddAttribute(P, LLVMInRegAttribute);
+		lp_add_function_attr(ctx->main_fn, i + 1, LP_FUNC_ATTR_INREG);
 	}
 	tgsi_scan_shader(tokens, &shader_info);
 
