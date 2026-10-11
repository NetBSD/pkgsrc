# $NetBSD: buildlink3.mk,v 1.14 2026/10/11 16:02:20 wiz Exp $

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=22.1.0
BUILDLINK_ABI_DEPENDS.compiler-rt?=	compiler-rt>=22.1.8nb1
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../lang/compiler-rt

.include "../../lang/llvm/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
