# $NetBSD: buildlink.mk,v 1.1.1.1 2002/03/24 20:14:37 wiz Exp $
#
# This Makefile fragment is included by packages that use SDL_gfx.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.SDL_gfx to the dependency pattern
#     for the version of SDL_gfx desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SDL_gfx_BUILDLINK_MK)
SDL_gfx_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.SDL_gfx?=	SDL_gfx>=2.0.3
DEPENDS+=	${BUILDLINK_DEPENDS.SDL_gfx}:../../devel/SDL_gfx

EVAL_PREFIX+=			BUILDLINK_PREFIX.SDL_gfx=SDL_gfx

BUILDLINK_PREFIX.SDL_gfx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL_gfx=	include/SDL_framerate.h
BUILDLINK_FILES.SDL_gfx+=	include/SDL_gfxPrimitives.h
BUILDLINK_FILES.SDL_gfx+=	include/SDL_gfxPrimitives_font.h
BUILDLINK_FILES.SDL_gfx+=	include/SDL_imageFilter.h
BUILDLINK_FILES.SDL_gfx+=	include/SDL_rotozoom.h
BUILDLINK_FILES.SDL_gfx+=	lib/libSDL_gfx.*

.include "../../devel/SDL/buildlink.mk"

BUILDLINK_TARGETS.SDL_gfx=	SDL_gfx-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.SDL_gfx}

pre-configure: ${BUILDLINK_TARGETS.SDL_gfx}
SDL_gfx-buildlink: _BUILDLINK_USE

.endif	# SDL_gfx_BUILDLINK_MK
