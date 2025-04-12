# $NetBSD: buildlink3.mk,v 1.2 2025/04/12 06:54:22 wiz Exp $

BUILDLINK_TREE+=	libtheoraplay

.if !defined(LIBTHEORAPLAY_BUILDLINK3_MK)
LIBTHEORAPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtheoraplay+=	libtheoraplay>=0.0.20190909
BUILDLINK_ABI_DEPENDS.libtheoraplay?=	libtheoraplay>=0.0.20210704nb1
BUILDLINK_PKGSRCDIR.libtheoraplay?=	../../multimedia/libtheoraplay

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.endif	# LIBTHEORAPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtheoraplay
