# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/03 08:17:22 wiz Exp $

.if !defined(SDL_MIXER_BUILDLINK2_MK)
SDL_MIXER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		SDL_mixer
BUILDLINK_DEPENDS.SDL_mixer?=	SDL_mixer>=1.2.0
BUILDLINK_PKGSRCDIR.SDL_mixer?=	../../audio/SDL_mixer

EVAL_PREFIX+=				BUILDLINK_PREFIX.SDL_mixer=SDL_mixer
BUILDLINK_PREFIX.SDL_mixer_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL_mixer=		include/SDL_mixer/*
BUILDLINK_FILES.SDL_mixer+=		lib/libSDL_mixer-*
BUILDLINK_FILES.SDL_mixer+=		lib/libSDL_mixer.*

.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	SDL_mixer-buildlink

SDL_mixer-buildlink: _BUILDLINK_USE

.endif	# SDL_MIXER_BUILDLINK2_MK
