# $NetBSD: buildlink.mk,v 1.2 2001/10/03 20:56:40 jlam Exp $
#
# This Makefile fragment is included by packages that use SDL_mixer.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.SDL_mixer to the dependency pattern
#     for the version of SDL_mixer desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SDL_MIXER_BUILDLINK_MK)
SDL_MIXER_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.SDL_mixer?=	SDL-mixer>=1.2.0
DEPENDS+=	${BUILDLINK_DEPENDS.SDL_mixer}:../../devel/SDL-mixer

BUILDLINK_PREFIX.SDL_mixer=		${LOCALBASE}
BUILDLINK_FILES.SDL_mixer=		include/SDL_mixer/*
BUILDLINK_FILES.SDL_mixer+=		lib/libSDL_mixer-*
BUILDLINK_FILES.SDL_mixer+=		lib/libSDL_mixer.*

.include "../../devel/SDL/buildlink.mk"

BUILDLINK_TARGETS.SDL_mixer=	SDL_mixer-buildlink
BUILDLINK_TARGETS.SDL_mixer+=	SDL_mixer-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.SDL_mixer}

BUILDLINK_CONFIG.SDL_mixer=		${LOCALBASE}/bin/SDL_mixer-config
BUILDLINK_CONFIG_WRAPPER.SDL_mixer=	${BUILDLINK_DIR}/bin/SDL_mixer-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.SDL_mixer}|${BUILDLINK_CONFIG.SDL_mixer}|g"

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
SDL_MIXER_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.SDL_mixer}
CONFIGURE_ENV+=		SDL_MIXER_CONFIG="${SDL_MIXER_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.SDL_mixer}
SDL_mixer-buildlink: _BUILDLINK_USE
SDL_mixer-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# SDL_MIXER_BUILDLINK_MK
