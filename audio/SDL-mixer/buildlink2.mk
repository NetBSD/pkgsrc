# $NetBSD: buildlink2.mk,v 1.1 2002/08/27 18:40:07 jlam Exp $

.if !defined(SDL_MIXER_BUILDLINK2_MK)
SDL_MIXER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		SDL-mixer
BUILDLINK_DEPENDS.SDL-mixer?=	SDL-mixer>=1.2.0
BUILDLINK_PKGSRCDIR.SDL-mixer?=	../../audio/SDL-mixer

EVAL_PREFIX+=				BUILDLINK_PREFIX.SDL-mixer=SDL-mixer
BUILDLINK_PREFIX.SDL-mixer_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL-mixer=		include/SDL_mixer/*
BUILDLINK_FILES.SDL-mixer+=		lib/libSDL_mixer-*
BUILDLINK_FILES.SDL-mixer+=		lib/libSDL_mixer.*

.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	SDL-mixer-buildlink

SDL-mixer-buildlink: _BUILDLINK_USE

.endif	# SDL_MIXER_BUILDLINK2_MK
