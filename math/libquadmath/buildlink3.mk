# $NetBSD: buildlink3.mk,v 1.1 2021/05/16 10:10:54 nia Exp $

BUILDLINK_TREE+=	libquadmath

.if !defined(LIBQUADMATH_BUILDLINK3_MK)
LIBQUADMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libquadmath+=	libquadmath>=11.0
BUILDLINK_ABI_DEPENDS.libquadmath+=	libquadmath>=11.0
BUILDLINK_PKGSRCDIR.libquadmath?=	../../math/libquadmath
.endif

BUILDLINK_TREE+=	-libquadmath
