# $NetBSD: buildlink3.mk,v 1.4 2025/05/09 19:37:15 wiz Exp $

BUILDLINK_TREE+=	spirv-llvm-translator

.if !defined(SPIRV_LLVM_TRANSLATOR_BUILDLINK3_MK)
SPIRV_LLVM_TRANSLATOR_BUILDLINK3_MK:=

GCC_REQD+=	7 # sync with llvm

BUILDLINK_API_DEPENDS.spirv-llvm-translator+=	spirv-llvm-translator>=14.0.0
BUILDLINK_ABI_DEPENDS.spirv-llvm-translator?=	spirv-llvm-translator>=19.1.7nb1
BUILDLINK_PKGSRCDIR.spirv-llvm-translator?=	../../parallel/spirv-llvm-translator

.include "../../lang/llvm/buildlink3.mk"

.endif	# SPIRV_LLVM_TRANSLATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-spirv-llvm-translator
