# $NetBSD: buildlink3.mk,v 1.7 2025/08/10 10:38:51 wiz Exp $

BUILDLINK_TREE+=	imath

.if !defined(IMATH_BUILDLINK3_MK)
IMATH_BUILDLINK3_MK:=

# C++14
GCC_REQD+=	6

BUILDLINK_API_DEPENDS.imath+=	imath>=3.0.4
BUILDLINK_ABI_DEPENDS.imath+=	imath>=3.2.0
BUILDLINK_PKGSRCDIR.imath?=	../../math/imath
.endif	# IMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-imath
