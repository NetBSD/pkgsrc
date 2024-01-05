# $NetBSD: buildlink3.mk,v 1.1 2024/01/05 11:14:02 nros Exp $

BUILDLINK_TREE+=	libavif

.if !defined(LIBAVIF_BUILDLINK3_MK)
LIBAVIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libavif+=	libavif>=1.0.3
BUILDLINK_PKGSRCDIR.libavif?=	../../graphics/libavif

.endif	# LIBAVIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libavif
