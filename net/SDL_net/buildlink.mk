# $NetBSD: buildlink.mk,v 1.3 2001/07/27 13:33:33 jlam Exp $
#
# This Makefile fragment is included by packages that use SDL_net.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.SDL_net to the dependency pattern
#     for the version of SDL_net desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SDL_NET_BUILDLINK_MK)
SDL_NET_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.SDL_net?=	SDL_net>=1.2.0
DEPENDS+=	${BUILDLINK_DEPENDS.SDL_net}:../../net/SDL_net

EVAL_PREFIX+=			BUILDLINK_PREFIX.SDL_net=SDL_net
BUILDLINK_PREFIX.SDL_net_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL_net=	include/SDL/SDL_net.h
BUILDLINK_FILES.SDL_net+=	lib/libSDL_net-*
BUILDLINK_FILES.SDL_net+=	lib/libSDL_net.*

.include "../../devel/SDL/buildlink.mk"

BUILDLINK_TARGETS.SDL_net=	SDL_net-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.SDL_net}

pre-configure: ${BUILDLINK_TARGETS.SDL_net}
SDL_net-buildlink: _BUILDLINK_USE

.endif	# SDL_NET_BUILDLINK_MK
