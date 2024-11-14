# $NetBSD: buildlink3.mk,v 1.10 2024/11/14 22:21:21 wiz Exp $

BUILDLINK_TREE+=	opencl-clang

.if !defined(OPENCL_CLANG_BUILDLINK3_MK)
OPENCL_CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencl-clang+=	opencl-clang>=10.0.0.1
BUILDLINK_ABI_DEPENDS.opencl-clang+=	opencl-clang>=18.1.0nb3
BUILDLINK_PKGSRCDIR.opencl-clang?=	../../parallel/opencl-clang

.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.endif	# OPENCL_CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencl-clang
