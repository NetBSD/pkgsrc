# $NetBSD: buildlink3.mk,v 1.2 2019/06/02 08:35:56 adam Exp $

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=8.0.0
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../lang/compiler-rt

.include "../../lang/llvm/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
