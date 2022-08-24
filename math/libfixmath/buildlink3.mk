# $NetBSD: buildlink3.mk,v 1.1 2022/08/24 12:49:24 ryoon Exp $

BUILDLINK_TREE+=	libfixmath

.if !defined(LIBFIXMATH_BUILDLINK3_MK)
LIBFIXMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfixmath+=	libfixmath>=0.0.0pre20220623
BUILDLINK_PKGSRCDIR.libfixmath?=	../../math/libfixmath
.endif	# LIBFIXMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfixmath
