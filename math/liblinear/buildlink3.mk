# $NetBSD: buildlink3.mk,v 1.2 2017/05/21 10:40:28 adam Exp $

BUILDLINK_TREE+=	liblinear

.if !defined(LIBLINEAR_BUILDLINK3_MK)
LIBLINEAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblinear+=	liblinear>=2.1
BUILDLINK_PKGSRCDIR.liblinear?=		../../math/liblinear
.endif	# LIBLINEAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblinear
