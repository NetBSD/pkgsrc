# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:23:57 joerg Exp $

BUILDLINK_TREE+=	libvorbis

.if !defined(LIBVORBIS_BUILDLINK3_MK)
LIBVORBIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvorbis+=	libvorbis>=1.0.1
BUILDLINK_ABI_DEPENDS.libvorbis+=	libvorbis>=1.1.0nb1
BUILDLINK_PKGSRCDIR.libvorbis?=	../../audio/libvorbis

.include "../../multimedia/libogg/buildlink3.mk"
.endif # LIBVORBIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvorbis
