# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:04 joerg Exp $

BUILDLINK_TREE+=	libtheora

.if !defined(LIBTHEORA_BUILDLINK3_MK)
LIBTHEORA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtheora+=	libtheora>=1.0alpha3
BUILDLINK_ABI_DEPENDS.libtheora+=	libtheora>=1.0alpha3nb1
BUILDLINK_PKGSRCDIR.libtheora?=	../../multimedia/libtheora

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif # LIBTHEORA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtheora
