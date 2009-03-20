# $NetBSD: buildlink3.mk,v 1.16 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	SDL_mixer

.if !defined(SDL_MIXER_BUILDLINK3_MK)
SDL_MIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb2
BUILDLINK_ABI_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.6nb5
BUILDLINK_PKGSRCDIR.SDL_mixer?=	../../audio/SDL_mixer
BUILDLINK_INCDIRS.SDL_mixer?=	include/SDL

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.endif # SDL_MIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_mixer
