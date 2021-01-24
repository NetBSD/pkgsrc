# $NetBSD: buildlink3.mk,v 1.1 2021/01/24 18:22:25 maya Exp $

BUILDLINK_TREE+=	libtheoraplay

.if !defined(LIBTHEORAPLAY_BUILDLINK3_MK)
LIBTHEORAPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtheoraplay+=	libtheoraplay>=0.0.20190909
BUILDLINK_PKGSRCDIR.libtheoraplay?=	../../multimedia/libtheoraplay

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.endif	# LIBTHEORAPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtheoraplay
