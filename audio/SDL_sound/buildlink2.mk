# $NetBSD: buildlink2.mk,v 1.6 2004/01/18 13:51:15 cube Exp $

.if !defined(SDL_SOUND_BUILDLINK2_MK)
SDL_SOUND_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		SDL_sound
BUILDLINK_DEPENDS.SDL_sound?=	SDL_sound>=1.0.1
BUILDLINK_PKGSRCDIR.SDL_sound?=	../../audio/SDL_sound

EVAL_PREFIX+=				BUILDLINK_PREFIX.SDL_sound=SDL_sound
BUILDLINK_PREFIX.SDL_sound_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL_sound=		include/SDL/SDL_sound.h
BUILDLINK_FILES.SDL_sound+=		lib/libSDL_sound-*
BUILDLINK_FILES.SDL_sound+=		lib/libSDL_sound.*

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"

BUILDLINK_TARGETS+=	SDL_sound-buildlink

SDL_sound-buildlink: _BUILDLINK_USE

.endif	# SDL_SOUND_BUILDLINK2_MK
