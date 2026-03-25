# $NetBSD: buildlink3.mk,v 1.11 2026/03/25 22:56:26 wiz Exp $

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=20.1.0
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../lang/compiler-rt

.include "../../lang/llvm/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
