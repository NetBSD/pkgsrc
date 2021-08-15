# $NetBSD: buildlink3.mk,v 1.2 2021/08/15 14:14:43 wiz Exp $

BUILDLINK_TREE+=	imath

.if !defined(IMATH_BUILDLINK3_MK)
IMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imath+=	imath>=3.0.4
BUILDLINK_ABI_DEPENDS.imath+=	imath>=3.1
BUILDLINK_PKGSRCDIR.imath?=	../../math/imath
.endif	# IMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-imath
