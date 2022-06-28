# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:34:37 wiz Exp $

BUILDLINK_TREE+=	libquadmath

.if !defined(LIBQUADMATH_BUILDLINK3_MK)
LIBQUADMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libquadmath+=	libquadmath>=11.0
BUILDLINK_ABI_DEPENDS.libquadmath+=	libquadmath>=11.1.0nb1
BUILDLINK_PKGSRCDIR.libquadmath?=	../../math/libquadmath
.endif

BUILDLINK_TREE+=	-libquadmath
