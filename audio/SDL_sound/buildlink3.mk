# $NetBSD: buildlink3.mk,v 1.16 2012/01/13 10:54:44 obache Exp $

BUILDLINK_TREE+=	SDL_sound

.if !defined(SDL_SOUND_BUILDLINK3_MK)
SDL_SOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL_sound+=	SDL_sound>=1.0.3
BUILDLINK_ABI_DEPENDS.SDL_sound?=	SDL_sound>=1.0.3nb4
BUILDLINK_PKGSRCDIR.SDL_sound?=	../../audio/SDL_sound

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.endif # SDL_SOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL_sound
