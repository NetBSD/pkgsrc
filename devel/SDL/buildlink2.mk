# $NetBSD: buildlink2.mk,v 1.10 2003/12/08 20:25:51 reed Exp $

.if !defined(SDL_BUILDLINK2_MK)
SDL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		SDL
BUILDLINK_DEPENDS.SDL?=		SDL>=1.2.5nb5
BUILDLINK_PKGSRCDIR.SDL?=	../../devel/SDL

EVAL_PREFIX+=		BUILDLINK_PREFIX.SDL=SDL
BUILDLINK_PREFIX.SDL_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDL=	include/SDL/*
BUILDLINK_FILES.SDL+=	lib/libSDL.*
BUILDLINK_FILES.SDL+=	lib/libSDLmain.*

USE_X11=		YES

.include "../../mk/bsd.prefs.mk"

PTHREAD_OPTS+=		require

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/aalib-x11/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=		SDL-buildlink

SDL-buildlink: _BUILDLINK_USE

.endif	# SDL_BUILDLINK2_MK
