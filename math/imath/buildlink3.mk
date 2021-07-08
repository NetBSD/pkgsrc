# $NetBSD: buildlink3.mk,v 1.1 2021/07/08 21:09:04 markd Exp $

BUILDLINK_TREE+=	imath

.if !defined(IMATH_BUILDLINK3_MK)
IMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imath+=	imath>=3.0.4
BUILDLINK_PKGSRCDIR.imath?=	../../math/imath
.endif	# IMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-imath
