# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:03:55 rillig Exp $

BUILDLINK_TREE+=	libvorbis

.if !defined(LIBVORBIS_BUILDLINK3_MK)
LIBVORBIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvorbis+=	libvorbis>=1.0.1
BUILDLINK_ABI_DEPENDS.libvorbis+=	libvorbis>=1.1.0nb1
BUILDLINK_PKGSRCDIR.libvorbis?=		../../audio/libvorbis

.include "../../multimedia/libogg/buildlink3.mk"
.endif # LIBVORBIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvorbis
