# $NetBSD: buildlink3.mk,v 1.2 2021/06/09 14:56:51 nia Exp $

BUILDLINK_TREE+=	spirv-llvm-translator

.if !defined(SPIRV_LLVM_TRANSLATOR_BUILDLINK3_MK)
SPIRV_LLVM_TRANSLATOR_BUILDLINK3_MK:=

GCC_REQD+=	5 # C++14

BUILDLINK_API_DEPENDS.spirv-llvm-translator+=	spirv-llvm-translator>=10.0.0
BUILDLINK_PKGSRCDIR.spirv-llvm-translator?=	../../parallel/spirv-llvm-translator

.include "../../lang/llvm/buildlink3.mk"

.endif	# SPIRV_LLVM_TRANSLATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-spirv-llvm-translator
