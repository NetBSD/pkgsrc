# $NetBSD: buildlink3.mk,v 1.2 2024/11/05 22:29:20 wiz Exp $

BUILDLINK_TREE+=	libavif

.if !defined(LIBAVIF_BUILDLINK3_MK)
LIBAVIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libavif+=	libavif>=1.0.3
BUILDLINK_PKGSRCDIR.libavif?=	../../graphics/libavif

.include "../../multimedia/libaom/buildlink3.mk"
.endif	# LIBAVIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libavif
