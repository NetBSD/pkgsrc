# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:36 jlam Exp $

.if !defined(SDL_NET_BUILDLINK2_MK)
SDL_NET_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		SDL_net
BUILDLINK_DEPENDS.SDL_net?=	SDL_net>=1.2.0
BUILDLINK_PKGSRCDIR.SDL_net?=	../../net/SDL_net

EVAL_PREFIX+=			BUILDLINK_PREFIX.SDL_net=SDL_net
BUILDLINK_PREFIX.SDL_net_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL_net=	include/SDL/SDL_net.h
BUILDLINK_FILES.SDL_net+=	lib/libSDL_net-*
BUILDLINK_FILES.SDL_net+=	lib/libSDL_net.*

.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	SDL_net-buildlink

SDL_net-buildlink: _BUILDLINK_USE

.endif	# SDL_NET_BUILDLINK2_MK
