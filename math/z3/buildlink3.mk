# $NetBSD: buildlink3.mk,v 1.5 2024/02/21 10:50:35 nia Exp $

BUILDLINK_TREE+=	z3

.if !defined(Z3_BUILDLINK3_MK)
Z3_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.z3+=	z3>=4.8.3
BUILDLINK_ABI_DEPENDS.z3?=	z3>=4.12.2nb1
BUILDLINK_PKGSRCDIR.z3?=	../../math/z3

.endif  # Z3_BUILDLINK3_MK

BUILDLINK_TREE+=	-z3
