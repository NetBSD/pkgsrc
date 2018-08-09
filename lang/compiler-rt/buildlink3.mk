# $NetBSD: buildlink3.mk,v 1.1 2018/08/09 13:40:34 jperkin Exp $

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=6.0.1
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../lang/compiler-rt

.include "../../lang/llvm/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
