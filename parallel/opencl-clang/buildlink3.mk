# $NetBSD: buildlink3.mk,v 1.14 2026/10/11 16:02:22 wiz Exp $

BUILDLINK_TREE+=	opencl-clang

.if !defined(OPENCL_CLANG_BUILDLINK3_MK)
OPENCL_CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencl-clang+=	opencl-clang>=10.0.0.1
BUILDLINK_ABI_DEPENDS.opencl-clang+=	opencl-clang>=21.1.3nb1
BUILDLINK_PKGSRCDIR.opencl-clang?=	../../parallel/opencl-clang

.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.endif	# OPENCL_CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencl-clang
