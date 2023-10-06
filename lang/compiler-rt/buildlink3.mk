# $NetBSD: buildlink3.mk,v 1.6 2023/10/06 19:15:20 adam Exp $

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=16.0.0<17
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../lang/compiler-rt

.include "../../lang/llvm/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
